#ifndef __EXPENSEREPORTSERVICE_H__
#define __EXPENSEREPORTSERVICE_H__

#pragma once

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "ExpenseReportService.grpc.pb.h"

// Logic and data behind the server's behavior.
class ExpenseReportServiceImpl final : public ::HyperNovaLabs::Api::Protos::Services::ExpenseReportService::Service
{
public:
  ExpenseReportServiceImpl() noexcept = default;
  ExpenseReportServiceImpl(const ExpenseReportServiceImpl &) = delete;
  ExpenseReportServiceImpl(ExpenseReportServiceImpl &&) = delete;
  ExpenseReportServiceImpl &operator=(const ExpenseReportServiceImpl &) = delete;
  ExpenseReportServiceImpl &operator=(ExpenseReportServiceImpl &&) = delete;

  virtual ~ExpenseReportServiceImpl() noexcept = default;

  virtual ::grpc::Status ListBill(::grpc::ServerContext *context, const ::google::protobuf::Empty *request, ::HyperNovaLabs::Api::Protos::Services::ListBillResponse *response) override;
  virtual ::grpc::Status GetBill(::grpc::ServerContext *context, const ::HyperNovaLabs::Api::Protos::Services::GetBillRequest *request, ::HyperNovaLabs::Api::Protos::Models::Bill *response) override;
  virtual ::grpc::Status CreateBill(::grpc::ServerContext *context, const ::HyperNovaLabs::Api::Protos::Services::CreateBillResquest *request, ::HyperNovaLabs::Api::Protos::Services::CreateBillResponse *response) override;
};

#endif // __EXPENSEREPORTSERVICE_H__