#include "ExpenseReportService.hpp"

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

Status ExpenseReportServiceImpl::ListBill(ServerContext *context, const Empty *request, ListBillResponse *response)
{
  return Status::OK;
}

Status ExpenseReportServiceImpl::GetBill(ServerContext *context, const GetBillRequest *request, Bill *response)
{  
  return Status::OK;
}

Status ExpenseReportServiceImpl::CreateBill(ServerContext *context, const CreateBillResquest *request, CreateBillResponse *response)
{
  return Status::OK;
}
