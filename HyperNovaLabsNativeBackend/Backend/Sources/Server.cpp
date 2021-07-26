#include "Server.hpp"


#include <iostream>
#include <string>
#include <string_view>

#include "EmployeeService.hpp"
#include "ExpenseReportService.hpp"

using ::grpc::Server;
using ::grpc::ServerBuilder;
using ::grpc::ServerContext;

using namespace ::HyperNovaLabs::Api::Protos::Models;
using namespace ::HyperNovaLabs::Api::Protos::Services;

void RunServer()
{
  std::string server_address("0.0.0.0:50051");

  EmployeeServiceImpl employee_service;
  ExpenseReportServiceImpl expense_report_service;

  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();

  ServerBuilder server_builder;

  // Listen on the given address without any authentication mechanism.
  server_builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  server_builder.RegisterService(&employee_service);
  server_builder.RegisterService(&expense_report_service);

  // Finally assemble the server.
  std::unique_ptr<Server> server(server_builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}
