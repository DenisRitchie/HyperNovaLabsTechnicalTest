
# https://www.w3cschool.cn/doc_cmake_3_8/cmake_3_8-command-target_include_directories.html

target_include_directories(${PROJECT_NAME}
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/Include
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Libs/NoesisGUI/Include>
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Libs/NoesisGUI/App/ApplicationLauncher/Include>
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Libs/NoesisGUI/App/Display/Include>
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Libs/NoesisGUI/App/DisplayLauncher/Include>
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Libs/NoesisGUI/App/Interactivity/Include>
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Libs/NoesisGUI/App/Launcher/Include>
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Libs/NoesisGUI/App/MediaElement/Include>
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Libs/NoesisGUI/App/Providers/Include>
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Libs/NoesisGUI/App/Theme/Include>
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Libs/NoesisGUI/Render/GLRenderDevice/Include>
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Libs/NoesisGUI/Render/RenderContext/Include>
)
