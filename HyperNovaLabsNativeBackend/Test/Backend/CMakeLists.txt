cmake_minimum_required(VERSION 3.20)

project(TestBackend
  VERSION 1.0.0.0
  LANGUAGES C CXX
  DESCRIPTION "Test project for the backend"
)

message(STATUS "Building ${PROJECT_NAME} v${PROJECT_VERSION}: ${PROJECT_DESCRIPTION}")

add_executable(TestBackend
  Main.cpp
  EmployeeServiceClient.hpp
  EmployeeServiceClientTest.hpp
  EmployeeServiceClientTest.cpp
)

target_link_libraries(TestBackend
  PRIVATE ExpenseReportProtoLib
  PRIVATE libgtest
  PRIVATE libgmock
)

target_include_directories(TestBackend
  PRIVATE "${source_dir}/googletest/include"
  PRIVATE "${source_dir}/googlemock/include"
)

target_compile_features(TestBackend PUBLIC cxx_std_20)

add_test(NAME TestBackend COMMAND TestBackend)
