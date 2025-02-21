cmake_minimum_required(VERSION 3.13)

project(NoesisGUI
  VERSION 3.0.12.0
  LANGUAGES C CXX
  DESCRIPTION "Discover the most powerful User Interface middleware for videogames and realtime applications"
  HOMEPAGE_URL "https://www.noesisengine.com/"
)

add_library(NoesisGUI INTERFACE)

target_link_libraries(NoesisGUI
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Lib/Noesis.bc
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Lib/NoesisApp.bc
)

target_include_directories(NoesisGUI
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Include>
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/App/ApplicationLauncher/Include>
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/App/Display/Include>
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/App/DisplayLauncher/Include>
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/App/Interactivity/Include>
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/App/Launcher/Include>
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/App/MediaElement/Include>
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/App/Providers/Include>
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/App/Theme/Include>
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/App/Theme/Data/Include>
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Render/GLRenderDevice/Include>
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Render/RenderContext/Include>
)

target_compile_options(NoesisGUI
  INTERFACE -pipe
  INTERFACE -Wall -Werror -Wfatal-errors -Wtype-limits
  INTERFACE -fno-exceptions -fno-threadsafe-statics
  INTERFACE -Oz -DNDEBUG -flto
)

target_compile_definitions(NoesisGUI
  INTERFACE -DNS_BUILD
  INTERFACE -DNS_CONFIG=Release
  INTERFACE -DNS_VERSION=3.0.12
  INTERFACE -DNS_APP_FRAMEWORK
  INTERFACE -DNS_LICENSE
  INTERFACE -DNS_STATIC_LIBRARY
)
