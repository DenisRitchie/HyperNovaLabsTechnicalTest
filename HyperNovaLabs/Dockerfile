FROM nginx:alpine AS base
WORKDIR /usr/share/nginx/html
EXPOSE 80


FROM emscripten/emsdk:2.0.0 AS build
RUN mkdir -p /usr/src/HyperNovaLabs
WORKDIR /usr/src/HyperNovaLabs
COPY . .
RUN rm -rf build
RUN rm -rf Publish
RUN rm -rf obj
RUN apt-get -qq -y update
RUN mkdir -p /usr/share/man/man1/
RUN apt-get -qq install -y --no-install-recommends ninja-build
RUN ln -s /usr/bin/python3 /usr/bin/python
RUN cmake --no-warn-unused-cli \
          -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE \
          -DCMAKE_BUILD_TYPE:STRING=Release \
          -DCMAKE_TOOLCHAIN_FILE:FILEPATH=/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake \
          -H/usr/src/HyperNovaLabs \
          -B/usr/src/HyperNovaLabs/build \
          -G Ninja
RUN cmake --build /usr/src/HyperNovaLabs/build \
          --config Release \
          --target all -j 14 --


FROM build AS publish
RUN cmake --build /usr/src/HyperNovaLabs/build \
          --config Release \
          --target install \
          -j 14 --


FROM base AS final
LABEL Name=HyperNovaLabs Version=0.0.1
WORKDIR /usr/share/nginx/html
COPY --from=publish /usr/src/HyperNovaLabs/Publish .