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
  std::cout << "Ejecutando: ListEmployee\n";

  for (const auto &value : m_Store)
  {
    auto new_employee = response->add_employees();
    value.CopyTo(new_employee);
  }

  std::cout << "Finalizando: ListEmployee\n";

  return Status::OK;
}

Status EmployeeServiceImpl::GetEmployee(ServerContext *context, const GetEmployeeRequest *request, Employee *response)
{
  std::cout << "Ejecutando: GetEmployee\n";

  auto result = m_Store.Find(request->identification());

  if (result.has_value())
  {
    response->CopyFrom(*result);
  }

  std::cout << "Finalizando: GetEmployee\n";

  return Status::OK;
}

Status EmployeeServiceImpl::CreateEmployee(ServerContext *context, const CreateEmployeeRequest *request, CreateEmployeeResponse *response)
{
  static int64_t n_invokes = 0;

  std::cout << "Ejecutando: CreateEmployee (" << ++n_invokes << ")" << std::endl;

  m_Store.Add(request->employee());
  response->mutable_employee()->CopyFrom(request->employee());

  std::cout << "Finalizando: CreateEmployee\n";
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
