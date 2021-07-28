# Imagen Base
FROM alpine:3.14 AS base
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
COPY --from=publish /source/build/publish/Release/bin .
ENTRYPOINT ["ExpenseReportBackend"]