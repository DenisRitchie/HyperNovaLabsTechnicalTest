cmake_minimum_required(VERSION 3.20)

project(SqlClient
  VERSION 1.0.0.0
  LANGUAGES C CXX
  DESCRIPTION "Sql Server Client"
  HOMEPAGE_URL "https://github.com/DenisRitchie/HyperNovaLabsTechnicalTest"
)

message(STATUS "Building ${PROJECT_NAME} v${PROJECT_VERSION}: ${PROJECT_DESCRIPTION}")

add_library(SqlClient SHARED "")

add_library(HyperNovaLabs::SqlClient ALIAS SqlClient)

target_sources(SqlClient
  PUBLIC
    ${PROJECT_SOURCE_DIR}/Includes/SqlHeaders.hpp
    ${PROJECT_SOURCE_DIR}/Includes/SqlClientFactory.hpp
    ${PROJECT_SOURCE_DIR}/Includes/SqlCommand.hpp
    ${PROJECT_SOURCE_DIR}/Includes/SqlConnection.hpp
    ${PROJECT_SOURCE_DIR}/Includes/SqlDataAdapter.hpp
    ${PROJECT_SOURCE_DIR}/Includes/SqlParameter.hpp
    ${PROJECT_SOURCE_DIR}/Sources/SqlClientFactory.cpp
    ${PROJECT_SOURCE_DIR}/Sources/SqlCommand.cpp
    ${PROJECT_SOURCE_DIR}/Sources/SqlConnection.cpp
    ${PROJECT_SOURCE_DIR}/Sources/SqlDataAdapter.cpp
    ${PROJECT_SOURCE_DIR}/Sources/SqlParameter.cpp
)

target_include_directories(SqlClient PUBLIC ${PROJECT_SOURCE_DIR}/Includes)

target_compile_features(SqlClient PUBLIC cxx_std_20)

install(
  TARGETS SqlClient
  CONFIGURATIONS Debug
  RUNTIME DESTINATION Debug/bin # .out files -> .exe
  LIBRARY DESTINATION Debug/bin # .so  files -> .dll
  ARCHIVE DESTINATION Debug/bin # .a   files -> .lib
)

install(
  TARGETS SqlClient
  CONFIGURATIONS Release
  RUNTIME DESTINATION Release/bin # .out files -> .exe
  LIBRARY DESTINATION Release/bin # .so  files -> .dll
  ARCHIVE DESTINATION Release/bin # .a   files -> .lib
)
