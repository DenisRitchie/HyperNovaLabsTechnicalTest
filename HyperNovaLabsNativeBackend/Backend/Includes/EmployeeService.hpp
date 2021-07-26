#ifndef __EMPLOYEESERVICE_H__
#define __EMPLOYEESERVICE_H__

#pragma once

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "EmployeeService.grpc.pb.h"

// Logic and data behind the server's behavior.
class EmployeeServiceImpl final : public ::HyperNovaLabs::Api::Protos::Services::EmployeeService::Service
{
public:
  EmployeeServiceImpl() noexcept = default;
  EmployeeServiceImpl(const EmployeeServiceImpl &) = delete;
  EmployeeServiceImpl(EmployeeServiceImpl &&) = delete;
  EmployeeServiceImpl &operator=(const EmployeeServiceImpl &) = delete;
  EmployeeServiceImpl &operator=(EmployeeServiceImpl &&) = delete;

  virtual ~EmployeeServiceImpl() noexcept = default;

  virtual ::grpc::Status ListEmployee(::grpc::ServerContext *context, const ::google::protobuf::Empty *request, ::HyperNovaLabs::Api::Protos::Services::ListEmployeeResponse *response) override;
  virtual ::grpc::Status GetEmployee(::grpc::ServerContext *context, const ::HyperNovaLabs::Api::Protos::Services::GetEmployeeRequest *request, ::HyperNovaLabs::Api::Protos::Models::Employee *response) override;
  virtual ::grpc::Status CreateEmployee(::grpc::ServerContext *context, const ::HyperNovaLabs::Api::Protos::Services::CreateEmployeeRequest *request, ::HyperNovaLabs::Api::Protos::Services::CreateEmployeeResponse *response) override;
  virtual ::grpc::Status UpdateEmployee(::grpc::ServerContext *context, const ::HyperNovaLabs::Api::Protos::Services::UpdateEmployeeRequest *request, ::HyperNovaLabs::Api::Protos::Services::UpdateEmployeeResponse *response) override;
  virtual ::grpc::Status DeleteEmployee(::grpc::ServerContext *context, const ::HyperNovaLabs::Api::Protos::Services::DeleteEmployeeRequest *request, ::HyperNovaLabs::Api::Protos::Services::DeleteEmployeeResponse *response) override;
  virtual ::grpc::Status ListOfAnEmployeeBills(::grpc::ServerContext *context, const ::HyperNovaLabs::Api::Protos::Services::ListOfAnEmployeesBillRequest *request, ::HyperNovaLabs::Api::Protos::Services::ListOfAnEmployeesBillResponse *response) override;
};

#endif // __EMPLOYEESERVICE_H__