FROM gcc:11.1

RUN mkdir -p /source
WORKDIR /source

RUN wget -q -O cmake-linux.sh https://github.com/Kitware/CMake/releases/download/v3.21.1/cmake-3.21.1-Linux-x86_64.sh
RUN sh cmake-linux.sh -- --skip-license --prefix=/usr/local/ --exclude-subdir
RUN rm cmake-linux.sh

RUN git clone --recurse-submodules -b v1.39.0 https://github.com/grpc/grpc
WORKDIR /source/grpc

RUN mkdir -p third_party/abseil-cpp/cmake/build
WORKDIR /source/grpc/third_party/abseil-cpp/cmake/build
RUN cmake -DCMAKE_POSITION_INDEPENDENT_CODE=TRUE ../..
RUN make -j
RUN make install
WORKDIR /source/grpc

RUN mkdir -p cmake/build
WORKDIR /source/grpc/cmake/build
RUN cmake -DgRPC_INSTALL=ON -DgRPC_BUILD_TESTS=OFF ../.. 
RUN make -j
RUN make install

WORKDIR /
RUN rm -R -d /source

ENTRYPOINT [ "/bin/bash" ]