#ifndef __EMPLOYEESERVICECLIENT_H__
#define __EMPLOYEESERVICECLIENT_H__

#include <iostream>
#include <memory>
#include <string>
#include <optional>
#include <vector>
#include <iterator>
#include <tuple>

#include <grpcpp/grpcpp.h>

#include "EmployeeService.grpc.pb.h"

#include "GrpcServerInfo.hpp"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using namespace HyperNovaLabs::Api::Protos::Models;
using namespace HyperNovaLabs::Api::Protos::Services;

class EmployeeServiceClient
{
public:
  EmployeeServiceClient(std::shared_ptr<Channel> channel) noexcept
    : m_Stub{ EmployeeService::NewStub(channel) }
  {
  }

  std::vector<Employee> ListEmployee() const noexcept
  {
    ListEmployeeResponse response;
    ClientContext context;

    Status status = m_Stub->ListEmployee(&context, google::protobuf::Empty{ }, &response);

    if ( status.ok() )
    {
      std::vector<Employee> result_values;
      result_values.reserve(response.employees_size());

      std::for_each_n(std::move_iterator{ response.mutable_employees()->begin() }, response.employees_size(),
      [&](const Employee &employee)
      {
        result_values.emplace_back( std::move(employee) );
      });

      return std::move(result_values);
    }
    else
    {
      std::cout << status.error_code() << ": " << status.error_message() << std::endl;
      return { };
    }
  }

  std::optional<Employee> GetEmployee(const std::string_view identification) const noexcept
  {
    // Data we are sending to the server.
    GetEmployeeRequest request;
    request.set_identification(identification.data(), identification.size());

    // Container for the data we expect from the server.
    Employee response;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // The actual RPC.
    Status status = m_Stub->GetEmployee(&context, request, &response);

    // Act upon its status.
    if ( status.ok() )
    {
      return std::move(response);
    }
    else
    {
      std::cout << status.error_code() << ": " << status.error_message() << std::endl;
      return std::nullopt;
    }
  }

  std::tuple<std::optional<Employee>, bool> CreateEmployee(const Employee& employee) const noexcept
  {
    CreateEmployeeRequest request;
    request.mutable_employee()->CopyFrom(employee);

    CreateEmployeeResponse response;
    ClientContext context;

    Status status = m_Stub->CreateEmployee(&context, request, &response);

    if ( status.ok() )
    {
      return std::make_tuple(response.employee(), true);
    }
    else
    {
      return std::make_tuple(std::nullopt, false);
    }
  }

private:
  std::unique_ptr<EmployeeService::Stub> m_Stub;
};

#endif // __EMPLOYEESERVICECLIENT_H__