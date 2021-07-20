cmake_minimum_required(VERSION 3.20)

project(ExpenseReport
  VERSION 1.0.0.0
  LANGUAGES C CXX
  DESCRIPTION "Expense report web application"
  HOMEPAGE_URL "https://github.com/DenisRitchie/HyperNovaLabsTechnicalTest"
)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/CMake")

configure_file(Templates/index.html.in index.html @ONLY)

include(GenerateBin2hFile)

generate_bin2h_file(
  TARGETS
    ${CMAKE_CURRENT_SOURCE_DIR}/Data/App.xaml
    ${CMAKE_CURRENT_SOURCE_DIR}/Data/MainWindow.xaml
    ${CMAKE_CURRENT_SOURCE_DIR}/Data/Images/File.png
    ${CMAKE_CURRENT_SOURCE_DIR}/Data/Images/FloppyDisk.png
    ${CMAKE_CURRENT_SOURCE_DIR}/Data/Images/FolderClosed.png
    ${CMAKE_CURRENT_SOURCE_DIR}/Data/Images/House.png
    ${CMAKE_CURRENT_SOURCE_DIR}/Data/Images/HyperNovaLabsLogo.png
    ${CMAKE_CURRENT_SOURCE_DIR}/Data/Images/Search.png
  DESTINATION
    ${CMAKE_CURRENT_BINARY_DIR}/Include
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_WEBGL2=1 -s NO_FILESYSTEM=1 -s WASM=1 -s INITIAL_MEMORY=67108864")

add_subdirectory(Libs/NoesisGUI)

add_executable(${PROJECT_NAME}
  Sources/Main.cpp
  ${BIND2H_HEADER_FILES_GENERATED}
)

target_compile_features(${PROJECT_NAME}
  PRIVATE cxx_std_17
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE NoesisGUI
)

target_include_directories(${PROJECT_NAME}
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/Include
)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/Publish)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/index.html DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/Publish)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.wasm DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/Publish)
