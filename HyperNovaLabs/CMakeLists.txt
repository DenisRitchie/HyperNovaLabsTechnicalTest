cmake_minimum_required(VERSION 3.20)

# https://retifrav.github.io/blog/2021/03/08/cmake-cpp-library/
# https://cmake.org/cmake/help/latest/command/project.html

project(ExpenseReport
  VERSION 1.0.0.0
  LANGUAGES C CXX
  DESCRIPTION "Aplicación Web de Reporte de Gastos"
  HOMEPAGE_URL ""
)

# https://stackoverflow.com/questions/3249459/for-the-cmake-include-command-what-is-the-difference-between-a-file-and-a-mod
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/CMake")

# https://cmake.org/cmake/help/latest/command/configure_file.html
configure_file(Templates/index.html.in index.html @ONLY)

include(GenerateBin2hFile)

generate_bin2h_file(
  TARGETS
    ${CMAKE_CURRENT_SOURCE_DIR}/Data/App.xaml
    ${CMAKE_CURRENT_SOURCE_DIR}/Data/MainWindow.xaml
  DESTINATION
    ${CMAKE_CURRENT_BINARY_DIR}/Include
)

add_executable(${PROJECT_NAME}
  Sources/Main.cpp
  ${BIND2H_HEADER_FILES_GENERATED}
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Libs/NoesisGUI/Lib/Noesis.bc
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Libs/NoesisGUI/Lib/NoesisApp.bc
)

# https://cmake.org/cmake/help/latest/prop_gbl/CMAKE_CXX_KNOWN_FEATURES.html
target_compile_features(${PROJECT_NAME}
    PRIVATE cxx_std_20
  # PRIVATE cxx_std_11
)

include(TargetCompileOptions)
include(TargetCompileDefinitions)
include(TargetIncludeDirectories)
include(SetTargetProperties)
