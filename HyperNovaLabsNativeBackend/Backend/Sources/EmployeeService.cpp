#include "EmployeeService.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include <algorithm>

#include <google/protobuf/arena.h>

using namespace grpc;
using namespace google::protobuf;
using namespace HyperNovaLabs::Api::Protos::Services;
using namespace HyperNovaLabs::Api::Protos::Models;

Status EmployeeServiceImpl::ListEmployee(ServerContext *context, const Empty *request, ListEmployeeResponse *response)
{
  return Status::OK;
}

Status EmployeeServiceImpl::GetEmployee(ServerContext *context, const GetEmployeeRequest *request, Employee *response)
{
  return Status::OK;
}

Status EmployeeServiceImpl::CreateEmployee(ServerContext *context, const CreateEmployeeRequest *request, CreateEmployeeResponse *response)
{
  return Status::OK;
}

Status EmployeeServiceImpl::UpdateEmployee(ServerContext *context, const UpdateEmployeeRequest *request, UpdateEmployeeResponse *response)
{
  return Status::OK;
}

Status EmployeeServiceImpl::DeleteEmployee(ServerContext *context, const DeleteEmployeeRequest *request, DeleteEmployeeResponse *response)
{
  return Status::OK;
}

Status EmployeeServiceImpl::ListOfAnEmployeeBills(ServerContext *context, const ListOfAnEmployeesBillRequest *request, ListOfAnEmployeesBillResponse *response)
{
  return Status::OK;
}
