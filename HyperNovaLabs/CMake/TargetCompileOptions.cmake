# https://emscripten.org/docs/compiling/Running-html-files-with-emrun.html
# https://emscripten.org/docs/compiling/Building-Projects
# https://github.com/emscripten-core/emscripten/blob/main/src/settings.js
# https://emscripten.org/docs/tools_reference/emcc.html#emcc-compiler-optimization-options

# https://emscripten.org/docs/tools_reference/emcc.html#emcc-compiler-optimization-options
# https://linux.die.net/man/1/clang
# https://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html#Option-Summary
# https://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html#Preprocessor-Options

#  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_WEBGL2=1 -s NO_FILESYSTEM=1 -s WASM=1 -s INITIAL_MEMORY=67108864")

target_compile_options(${PROJECT_NAME}
    PRIVATE -pipe
    PRIVATE -Wall -Werror -Wfatal-errors -Wtype-limits
    PRIVATE -fno-exceptions -frtti -fno-threadsafe-statics
    PRIVATE -sUSE_WEBGL2=1
    PRIVATE -sNO_FILESYSTEM=1
    PRIVATE -sWASM=1
    PRIVATE -sINITIAL_MEMORY=67108864
  # PRIVATE -D_DEBUG
  # PRIVATE -DNS_BUILD
  # PRIVATE -DNS_CONFIG=Debug
  # PRIVATE -DNS_VERSION=3.1.0b4
  # PRIVATE -DNS_APP_FRAMEWORK
  # PRIVATE -DNS_LICENSE
  # PRIVATE -DNS_STATIC_LIBRARY
  # PRIVATE -DNS_DEBUG
  # PRIVATE -DNS_PROFILE
  # PRIVATE -DNS_MINIMUM_LOG_LEVEL=1
    PRIVATE -flto
  # PRIVATE --shell-file ${CMAKE_CURRENT_SOURCE_DIR}/Templates/index.html
)
