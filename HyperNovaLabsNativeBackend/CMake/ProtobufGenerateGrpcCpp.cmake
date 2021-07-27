
#  protobuf_generate_grpc_cpp
#  --------------------------
#
#   Add custom commands to process ``.proto`` files to C++ using protoc and
#   GRPC plugin::
#
#     protobuf_generate_grpc_cpp [<ARGN>...]
#
#   ``ARGN``
#     ``.proto`` files
#
# protoc --grpc_out=generate_mock_code=true:build/includes --cpp_out=build/includes --plugin=protoc-gen-grpc=/bin/grpc_cpp_plugin -I Protos -I /include Protos/google/api/http.proto
#
# protoc --grpc_out=generate_mock_code=true:build/includes --cpp_out=build/includes --plugin=protoc-gen-grpc=/bin/grpc_cpp_plugin -I Protos -I /include Protos/google/api/http.proto
# protoc --grpc_out=generate_mock_code=true:build/includes --cpp_out=build/includes --plugin=protoc-gen-grpc=/bin/grpc_cpp_plugin -I Protos -I /include Protos/google/api/annotations.proto
#
# protoc --grpc_out=generate_mock_code=true:build/includes --cpp_out=build/includes --plugin=protoc-gen-grpc=/bin/grpc_cpp_plugin -I Protos -I /include Protos/Models/Bill.proto
# protoc --grpc_out=generate_mock_code=true:build/includes --cpp_out=build/includes --plugin=protoc-gen-grpc=/bin/grpc_cpp_plugin -I Protos -I /include Protos/Models/BillDescription.proto
# protoc --grpc_out=generate_mock_code=true:build/includes --cpp_out=build/includes --plugin=protoc-gen-grpc=/bin/grpc_cpp_plugin -I Protos -I /include Protos/Models/Employee.proto
#
# protoc --grpc_out=generate_mock_code=true:build/includes --cpp_out=build/includes --plugin=protoc-gen-grpc=/bin/grpc_cpp_plugin -I Protos -I /include Protos/EmployeeService.proto
# protoc --grpc_out=generate_mock_code=true:build/includes --cpp_out=build/includes --plugin=protoc-gen-grpc=/bin/grpc_cpp_plugin -I Protos -I /include Protos/ExpenseReportService.proto
#


# Javascript/Node - Client/Server
# 
# mkdir -p build/javascript-grpc
# protoc --js_out=import_style=commonjs,binary:build/javascript-grpc -I Protos -I /include \
# Protos/google/api/http.proto \
# Protos/google/api/annotations.proto \
# Protos/Models/Bill.proto \
# Protos/Models/BillDescription.proto \
# Protos/Models/Employee.proto \
# Protos/EmployeeService.proto \
# Protos/ExpenseReportService.proto
# 

# Javascript/Sockets - Client/Server
# 
# mkdir -p build/javascript-grpc
# protoc --js_out=library=HyperNovaLabsJs,binary:build/javascript-grpc -I Protos -I /include \
# Protos/google/api/http.proto \
# Protos/google/api/annotations.proto \
# Protos/Models/Bill.proto \
# Protos/Models/BillDescription.proto \
# Protos/Models/Employee.proto \
# Protos/EmployeeService.proto \
# Protos/ExpenseReportService.proto
# 

function(protobuf_generate_grpc_cpp proto_file)

  # Proto file: https://cmake.org/cmake/help/latest/command/get_filename_component.html
  get_filename_component(proto_file_absolute "${proto_file}" ABSOLUTE)
  
  # Running a command at configure time
  # https://cliutils.gitlab.io/modern-cmake/chapters/basics/programs.html

  execute_process(
    COMMAND ${_protobuf_protoc} 
      --grpc_out=generate_mock_code=true:${_grpc_proto_generated_dir}
      --cpp_out=${_grpc_proto_generated_dir}
      --plugin=protoc-gen-grpc=${_grpc_cpp_plugin_executable}
      -I ${CMAKE_SOURCE_DIR}/Protos
      -I ${_grpc_protobuf_wellknown_include_dir}
      ${proto_file_absolute}
  )

endfunction(protobuf_generate_grpc_cpp)
