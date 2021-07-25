cmake_minimum_required(VERSION 3.20)

project(ExpenseReportDatabase
  VERSION 1.0.0.0
  LANGUAGES C CXX
  DESCRIPTION "Expense Report Database"
  HOMEPAGE_URL "https://github.com/DenisRitchie/HyperNovaLabsTechnicalTest"
)

message(STATUS "Building ${PROJECT_NAME} v${PROJECT_VERSION}: ${PROJECT_DESCRIPTION}")

add_library(ExpenseReportDatabase SHARED "")

target_sources(ExpenseReportDatabase
  PUBLIC  
    ${PROJECT_SOURCE_DIR}/Includes/ExpenseReportContext.hpp
    ${PROJECT_SOURCE_DIR}/Sources/ExpenseReportContext.cpp
)

target_link_libraries(ExpenseReportDatabase
  PRIVATE
    SqlClient
)

target_compile_features(ExpenseReportDatabase PUBLIC cxx_std_20)
