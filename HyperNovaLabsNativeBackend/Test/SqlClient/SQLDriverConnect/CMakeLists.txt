cmake_minimum_required(VERSION 3.20)

project(TestSQLClient_SQLDriverConnect
  VERSION 1.0.0.0
  LANGUAGES C CXX
  DESCRIPTION "Test project for the SQL Server Native Client: SQLDriverConnect"
)

message(STATUS "Building Test Project \"${PROJECT_NAME}\" v${PROJECT_VERSION}: ${PROJECT_DESCRIPTION}")


add_executable(TestSQLClient_SQLDriverConnect
  Main.cpp
)

target_link_libraries(TestSQLClient_SQLDriverConnect
  PRIVATE ExpenseReportDatabase
  PRIVATE libgtest
  PRIVATE libgmock
)

target_include_directories(TestSQLClient_SQLDriverConnect
  PRIVATE "${source_dir}/googletest/include"
  PRIVATE "${source_dir}/googlemock/include"
)

target_compile_features(TestSQLClient_SQLDriverConnect PUBLIC cxx_std_20)

add_test(NAME TestSQLClient_SQLDriverConnect COMMAND TestSQLClient_SQLDriverConnect)
