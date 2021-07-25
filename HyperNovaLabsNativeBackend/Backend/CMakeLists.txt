cmake_minimum_required(VERSION 3.20)

project(ExpenseReportBackend
  VERSION 1.0.0.0
  LANGUAGES C CXX
  DESCRIPTION "Expense Report Backend"
  HOMEPAGE_URL "https://github.com/DenisRitchie/HyperNovaLabsTechnicalTest"
)

message(STATUS "Building ${PROJECT_NAME} v${PROJECT_VERSION}: ${PROJECT_DESCRIPTION}")

add_executable(ExpenseReportBackend
  ${PROJECT_SOURCE_DIR}/Sources/Main.cpp
)

target_link_libraries(ExpenseReportBackend
  PRIVATE
    SqlClient
    ExpenseReportDatabase
    ExpenseReportProtoLib   
)

target_compile_features(ExpenseReportBackend PUBLIC cxx_std_20)
