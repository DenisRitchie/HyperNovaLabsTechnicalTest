cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)

find_package(Threads REQUIRED)

# This branch assumes that gRPC and all its dependencies are already installed
# on this system, so they can be located by find_package().

# Find Protobuf installation
# Looks for protobuf-config.cmake file installed by Protobuf's cmake installation.
set(protobuf_MODULE_COMPATIBLE TRUE)
find_package(Protobuf CONFIG REQUIRED)
message(STATUS "Using protobuf ${Protobuf_VERSION}")

get_target_property(_grpc_protobuf_wellknown_include_dir protobuf::libprotoc INTERFACE_INCLUDE_DIRECTORIES)
set(_grpc_protobuf_protoc_executable ${PROTOBUF_PROTOC_EXECUTABLE})

set(_protobuf_libprotobuf protobuf::libprotobuf)
set(_grpc_grpcpp_reflection gRPC::grpc++_reflection)

find_program(_protobuf_protoc protoc)
# set(_protobuf_protoc $<TARGET_FILE:protobuf::protoc>)

# Find gRPC installation
# Looks for gRPCConfig.cmake file installed by gRPC's cmake installation.
find_package(gRPC CONFIG REQUIRED)
message(STATUS "Using gRPC ${gRPC_VERSION}")

set(_grpc_grpcpp gRPC::grpc++)

find_program(_grpc_cpp_plugin_executable grpc_cpp_plugin)
# set(_grpc_cpp_plugin_executable $<TARGET_FILE:gRPC::grpc_cpp_plugin>)

# Create directory for generated .proto files
# set(_grpc_proto_generated_dir ${CMAKE_BINARY_DIR}/includes)
set(_grpc_proto_generated_dir ${CMAKE_SOURCE_DIR}/Protos/Includes)
file(MAKE_DIRECTORY ${_grpc_proto_generated_dir})

# Libs
# gRPC::grpc++              ->  _grpc_grpcpp
# gRPC::grpc++_reflection   ->  _grpc_grpcpp_reflection
# protobuf::libprotobuf     ->  _protobuf_libprotobuf

# Commonly used variables

message(STATUS "Begin: Commonly Used Variables")
message(STATUS " _grpc_grpcpp:                         ${_grpc_grpcpp}")
message(STATUS " _grpc_grpcpp_reflection:              ${_grpc_grpcpp_reflection}")
message(STATUS " _protobuf_libprotobuf:                ${_protobuf_libprotobuf}")
message(STATUS " _grpc_protobuf_wellknown_include_dir: ${_grpc_protobuf_wellknown_include_dir}")
message(STATUS " _grpc_protobuf_protoc_executable:     ${_grpc_protobuf_protoc_executable}")
message(STATUS " _protobuf_protoc:                     ${_protobuf_protoc}")
message(STATUS " _grpc_cpp_plugin_executable:          ${_grpc_cpp_plugin_executable}")
message(STATUS " _grpc_proto_generated_dir:            ${_grpc_proto_generated_dir}")
message(STATUS "End: Commonly Used Variables")
