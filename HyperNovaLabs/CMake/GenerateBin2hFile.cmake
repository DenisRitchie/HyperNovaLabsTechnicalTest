# https://cmake.org/cmake/help/latest/command/function.html
# https://cmake.org/cmake/help/latest/command/macro.html#command:macro
# https://dev.to/10xlearner/how-to-correctly-create-a-cmake-function-with-proper-arguments-15en
# https://preshing.com/20170522/learn-cmakes-scripting-language-in-15-minutes/
# https://dev.to/10xlearner/how-to-correctly-create-a-cmake-function-with-proper-arguments-15en
# https://cmake.org/cmake/help/latest/command/cmake_parse_arguments.html

# https://cmake.org/cmake/help/latest/command/string.html#find

# https://smspillaz.wordpress.com/2015/01/25/performance-and-cmake_parse_arguments/
# https://github.com/rticommunity/rticonnextdds-examples/blob/master/resources/cmake/ConnextDdsAddExample.cmake
# https://code.i-harness.com/en/docs/cmake~3.10/command/cmake_parse_arguments
# https://crascit.com/2019/01/29/forwarding-command-arguments-in-cmake/

# https://cmake.org/cmake/help/latest/command/get_filename_component.html
# https://runebook.dev/en/docs/cmake/command/get_filename_component

# https://github.com/xbmc/xbmc/pull/10660/files/843ee770afd1fa8185ebf357594e3e0ecad44e13

# https://oleksandrkvl.github.io/2020/08/09/allowing-cmake-functions-to-return-value.html

####################################################################################################
function(generate_bin2h_file)
  set(Options)
  set(OneValueArgs DESTINATION)
  set(MultiValueArgs TARGETS)

  # cmake_parse_arguments(<prefix> <options> <one_value_keywords> <multi_value_keywords> args...)
  cmake_parse_arguments(BIN2H "${Options}" "${OneValueArgs}" "${MultiValueArgs}" ${ARGN})

  set(BIN2H ${CMAKE_CURRENT_SOURCE_DIR}/Libs/NoesisGUI/Tools/Bin2h/bin2h.py)

  foreach(Target IN LISTS BIN2H_TARGETS)
    get_filename_component(FileNameWe ${Target} NAME_WE)
    get_filename_component(FileName ${Target} NAME)
    
    string(CONCAT Bin2HOutput "${BIN2H_DESTINATION}/" "${FileName}" ".bin.h")
    
    add_custom_command(
      OUTPUT  ${Bin2HOutput}
      COMMAND ${BIN2H} ${Target} > ${Bin2HOutput}
      COMMENT "Compiling ${Target}"
    )

    list(APPEND HEADER_FILES_GENERATED ${Bin2HOutput})
  endforeach()

  set(BIND2H_HEADER_FILES_GENERATED ${HEADER_FILES_GENERATED} PARENT_SCOPE)
endfunction(generate_bin2h_file)
####################################################################################################

# https://gist.github.com/baiwfg2/39881ba703e9c74e95366ed422641609
# https://samthursfield.wordpress.com/2015/11/21/cmake-dependencies-between-targets-and-files-and-custom-commands/

# set(BIN2H ${CMAKE_CURRENT_SOURCE_DIR}/Libs/NoesisGUI/Tools/Bin2h/bin2h.py)
# set(BIN2H_OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Include)

#########################################################################

# add_custom_command(
#   OUTPUT  ${BIN2H_OUTPUT}/App.xaml.bin.h
#   COMMAND ${BIN2H} ${CMAKE_CURRENT_SOURCE_DIR}/Data/App.xaml > ${BIN2H_OUTPUT}/App.xaml.bin.h
#   COMMENT "Compiling App.xaml"
#   VERBATIM
# )

# add_custom_target(AppXamlBin ALL
#   DEPENDS ${BIN2H_OUTPUT}/App.xaml.bin.h
# )

#########################################################################

# add_custom_command(
#   OUTPUT  ${BIN2H_OUTPUT}/MainWindow.xaml.bin.h
#   COMMAND ${BIN2H} ${CMAKE_CURRENT_SOURCE_DIR}/Data/MainWindow.xaml > ${BIN2H_OUTPUT}/MainWindow.xaml.bin.h
#   COMMENT "Compiling MainWindow.xaml"
#   VERBATIM
# )

# add_custom_target(MainXamlBin ALL
#   DEPENDS ${BIN2H_OUTPUT}/MainWindow.xaml.bin.h
# )

#########################################################################

# add_dependencies(AppXamlBin MainXamlBin)

#########################################################################
