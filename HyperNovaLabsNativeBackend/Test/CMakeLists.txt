cmake_minimum_required(VERSION 3.20)

# https://github.com/tgamblin/ctest-demo/blob/master/CMakeLists.txt
# https://github.com/kaizouman/gtest-cmake-example/blob/master/test/CMakeLists.txt
# https://google.github.io/googletest/primer.html
enable_testing()

find_package(Threads REQUIRED)

# Enable ExternalProject CMake module
include(ExternalProject)

# Download and install GoogleTest
ExternalProject_Add(
  gtest
  URL https://github.com/google/googletest/archive/master.zip
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
  # Disable install step
  INSTALL_COMMAND ""
)

# Get GTest source and binary directories from CMake project
ExternalProject_Get_Property(gtest source_dir binary_dir)

message(STATUS "Begin: gtest")
message(STATUS " gtest source_dir: ${source_dir}")
message(STATUS " gtest binary_dir: ${binary_dir}")
message(STATUS "End: gtest")

# Create a libgtest target to be used as a dependency by test programs
add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)

# Set libgtest properties
set_target_properties(libgtest PROPERTIES
  "IMPORTED_LOCATION" "${binary_dir}/lib/libgtest.a"
  "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

# Create a libgmock target to be used as a dependency by test programs
add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)

# Set libgmock properties
set_target_properties(libgmock PROPERTIES
  "IMPORTED_LOCATION" "${binary_dir}/lib/libgmock.a"
  "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
# include_directories("${source_dir}/googletest/include" "${source_dir}/googlemock/include")

configure_file(DartConfiguration.tcl.in DartConfiguration.tcl @ONLY)

add_subdirectory(Backend)
