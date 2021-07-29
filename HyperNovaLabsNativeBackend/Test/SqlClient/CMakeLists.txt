cmake_minimum_required(VERSION 3.20)

project(TestSQLClient
  VERSION 1.0.0.0
  LANGUAGES C CXX
  DESCRIPTION "Test project for the SQL Server Native Client"
)

add_subdirectory(SQLDataSources)
add_subdirectory(SQLDriverConnect)
