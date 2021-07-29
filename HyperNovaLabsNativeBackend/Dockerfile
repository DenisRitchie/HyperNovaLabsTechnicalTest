# Imagen Base
FROM ubuntu:20.04 AS base
RUN mkdir -p /app
WORKDIR /app
EXPOSE 50051


# Imagen basada en GCC para compilar el proyecto
FROM gcc:11.1 AS build
COPY . /source
WORKDIR /source

# Instalar CMake
RUN wget -q -O cmake-linux.sh https://github.com/Kitware/CMake/releases/download/v3.21.1/cmake-3.21.1-Linux-x86_64.sh
RUN sh cmake-linux.sh -- --skip-license --prefix=/usr/local/ --exclude-subdir
RUN rm cmake-linux.sh

# Instalar Grpc
RUN git clone --recurse-submodules -b v1.39.0 https://github.com/grpc/grpc
WORKDIR /source/grpc

RUN mkdir -p third_party/abseil-cpp/cmake/build
WORKDIR /source/grpc/third_party/abseil-cpp/cmake/build
RUN cmake -DCMAKE_POSITION_INDEPENDENT_CODE=TRUE ../..
RUN make -j 14
RUN make install
WORKDIR /source/grpc

RUN mkdir -p cmake/build
WORKDIR /source/grpc/cmake/build
RUN cmake -DgRPC_INSTALL=ON -DgRPC_BUILD_TESTS=OFF ../.. 
RUN make -j 14
RUN make install

# Configurar el proyecto
WORKDIR /source
RUN cmake --no-warn-unused-cli \ 
          -DCMAKE_INSTALL_PREFIX:STRING=/source/build/publish \
          -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE \
          -DCMAKE_BUILD_TYPE:STRING=Release \
          -DCMAKE_C_COMPILER:FILEPATH=/usr/local/bin/gcc \
          -DCMAKE_CXX_COMPILER:FILEPATH=/usr/local/bin/g++ \
          -H/source -B/source/build -G "Unix Makefiles"

# Compilar el proyecto
RUN cmake --build /source/build --config Release --target all -j 14 --


# Imagen de publicación
FROM build AS publish
RUN cmake --build /source/build --config Release --target install -j 14 --


# Imagen final del proyecto
FROM base AS final
LABEL Name=HyperNovaLabsNativeBackend Version=0.0.1
WORKDIR /app

# TODO: Install the Microsoft ODBC driver for SQL Server

# https://docs.microsoft.com/en-us/sql/connect/odbc/linux-mac/installing-the-microsoft-odbc-driver-for-sql-server?view=sql-server-ver15#ubuntu17
# http://www.unixodbc.org/

# odbcinst --version
# unixODBC 2.3.7

# odbcinst -q -d
# [ODBC Driver 17 for SQL Server]

COPY --from=publish /source/build/publish/Release/bin/ExpenseReportBackend .
COPY --from=publish /source/build/publish/Release/bin/libSqlClient.so /usr/lib
COPY --from=publish /source/build/publish/Release/bin/libExpenseReportDatabase.so /usr/lib

COPY --from=publish /usr/lib/x86_64-linux-gnu/libnsl.so.2.0.1       /usr/lib/x86_64-linux-gnu/
COPY --from=publish /lib/x86_64-linux-gnu/libtirpc.so.3.0.0         /usr/lib/x86_64-linux-gnu/
COPY --from=publish /usr/lib/x86_64-linux-gnu/libgssapi_krb5.so.2.2 /usr/lib/x86_64-linux-gnu/
COPY --from=publish /usr/lib/x86_64-linux-gnu/libkrb5.so.3.3        /usr/lib/x86_64-linux-gnu/
COPY --from=publish /usr/lib/x86_64-linux-gnu/libk5crypto.so.3.1    /usr/lib/x86_64-linux-gnu/
COPY --from=publish /usr/lib/x86_64-linux-gnu/libkrb5support.so.0.1 /usr/lib/x86_64-linux-gnu/
COPY --from=publish /lib/x86_64-linux-gnu/libkeyutils.so.1.9        /usr/lib/x86_64-linux-gnu/
COPY --from=publish /usr/local/lib64/libstdc++.so.6.0.29            /usr/lib64

RUN ln -s /usr/lib/x86_64-linux-gnu/libnsl.so.2.0.1       /usr/lib/x86_64-linux-gnu/libnsl.so
RUN ln -s /usr/lib/x86_64-linux-gnu/libnsl.so.2.0.1       /usr/lib/x86_64-linux-gnu/libnsl.so.2
RUN ln -s /usr/lib/x86_64-linux-gnu/libtirpc.so.3.0.0     /usr/lib/x86_64-linux-gnu/libtirpc.so.3
RUN ln -s /usr/lib/x86_64-linux-gnu/libgssapi_krb5.so.2.2 /usr/lib/x86_64-linux-gnu/libgssapi_krb5.so.2
RUN ln -s /usr/lib/x86_64-linux-gnu/libkrb5.so.3.3        /usr/lib/x86_64-linux-gnu/libkrb5.so.3
RUN ln -s /usr/lib/x86_64-linux-gnu/libk5crypto.so.3.1    /usr/lib/x86_64-linux-gnu/libk5crypto.so.3
RUN ln -s /usr/lib/x86_64-linux-gnu/libkrb5support.so.0.1 /usr/lib/x86_64-linux-gnu/libkrb5support.so.0
RUN ln -s /usr/lib/x86_64-linux-gnu/libkeyutils.so.1.9    /usr/lib/x86_64-linux-gnu/libkeyutils.so.1
RUN ln -s -f /usr/lib64/libstdc++.so.6.0.29               /usr/lib/x86_64-linux-gnu/libstdc++.so.6
RUN ln -s /usr/lib64/libstdc++.so.6.0.29                  /usr/lib64/libstdc++.so
RUN ln -s /usr/lib64/libstdc++.so.6.0.29                  /usr/lib64/libstdc++.so.6

ENTRYPOINT ["./ExpenseReportBackend"]