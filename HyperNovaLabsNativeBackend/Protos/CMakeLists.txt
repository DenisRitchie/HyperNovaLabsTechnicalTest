cmake_minimum_required(VERSION 3.20)

project(ExpenseReportProtoLib
  VERSION 1.0.0.0
  LANGUAGES C CXX
  DESCRIPTION "Expense report proto models"
  HOMEPAGE_URL "https://github.com/DenisRitchie/HyperNovaLabsTechnicalTest"
)

include(ProtobufGenerateGrpcCpp)

protobuf_generate_grpc_cpp(google/api/annotations.proto)
protobuf_generate_grpc_cpp(google/api/http.proto)

protobuf_generate_grpc_cpp(Models/Bill.proto)
protobuf_generate_grpc_cpp(Models/BillDescription.proto)
protobuf_generate_grpc_cpp(Models/Employee.proto)

protobuf_generate_grpc_cpp(EmployeeService.proto)
protobuf_generate_grpc_cpp(ExpenseReportService.proto)

add_library(ExpenseReportProtoLib STATIC "")

foreach(_target google/api/annotations google/api/http Models/Bill Models/BillDescription Models/Employee EmployeeService ExpenseReportService)
  set(hw_proto_srcs "${_grpc_proto_generated_dir}/${_target}.pb.cc")
  set(hw_proto_hdrs "${_grpc_proto_generated_dir}/${_target}.pb.h")
  set(hw_grpc_srcs "${_grpc_proto_generated_dir}/${_target}.grpc.pb.cc")
  set(hw_grpc_hdrs "${_grpc_proto_generated_dir}/${_target}.grpc.pb.h")
  set(hw_grpc_mock_hdrs "${_grpc_proto_generated_dir}/${_target}_mock.grpc.pb.h")
  target_sources(ExpenseReportProtoLib
    PUBLIC
      ${hw_proto_srcs}
      ${hw_proto_hdrs}
      ${hw_grpc_srcs}
      ${hw_grpc_hdrs})
endforeach()

target_link_libraries(ExpenseReportProtoLib
  PUBLIC
    ${_grpc_grpcpp}
    ${_grpc_grpcpp_reflection}
    ${_protobuf_libprotobuf}
)

# target_include_directories(ExpenseReportProtoLib PUBLIC ${_grpc_proto_generated_dir})

target_compile_features(ExpenseReportProtoLib PUBLIC cxx_std_20)
