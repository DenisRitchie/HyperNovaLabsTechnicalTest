cmake_minimum_required(VERSION 3.20)

project(Backend
  VERSION 1.0.0.0
  LANGUAGES C CXX
  DESCRIPTION "Expense report backend application"
  HOMEPAGE_URL "https://github.com/DenisRitchie/HyperNovaLabsTechnicalTest"
)

message("${PROJECT_NAME} v${PROJECT_VERSION}: ${PROJECT_DESCRIPTION}")

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/CMake")

include(Common)

# include_directories(${_grpc_proto_generated_dir})
# include_directories(${_grpc_protobuf_wellknown_include_dir})

add_subdirectory(Protos)
add_subdirectory(Backend)
add_subdirectory(Database)
add_subdirectory(SqlClient)

# Useful Variables
# https://gitlab.kitware.com/cmake/community/-/wikis/doc/cmake/Useful-Variables
