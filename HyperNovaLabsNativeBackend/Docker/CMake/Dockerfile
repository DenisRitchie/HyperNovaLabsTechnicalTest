FROM gcc:11.1 AS build

RUN mkdir -p /source/cmake
WORKDIR /source/cmake

RUN wget -q -O cmake-linux.sh https://github.com/Kitware/CMake/releases/download/v3.21.1/cmake-3.21.1-Linux-x86_64.sh
RUN sh cmake-linux.sh -- --skip-license --prefix=/usr/local/ --exclude-subdir
RUN rm cmake-linux.sh
RUN cmake --version

WORKDIR /
RUN rm -R -d /source
ENTRYPOINT [ "/bin/bash" ]
