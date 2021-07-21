namespace HyperNovaLabs.Api.Services
{
    using Google.Protobuf.WellKnownTypes;

    using Grpc.Core;

    using HyperNovaLabs.Api.Protos;

    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Threading.Tasks;

    public class ExpenseReportService : Protos.ExpenseReportService.ExpenseReportServiceBase
    {
        private readonly static List<Models.Data> Values = new List<Models.Data>();

        public override Task<CreateDataResponse> CreateData(CreateDataRequest Request, ServerCallContext Context)
        {
            Values.Add(new Models.Data(Request.Data.Key, Request.Data.Value));

            return Task.FromResult(new CreateDataResponse
            {
                Data = Request.Data,
                DataCount = Values.Count,
                IsSuccess = true
            });
        }

        public override Task<ListDataResponse> ListData(Empty Request, ServerCallContext Context)
        {
            return Task.FromResult(new ListDataResponse
            {
                Values =
                {
                    Values.Select(V => new Data
                    {
                        Key = V.Key,
                        Value = V.Value
                    })
                }
            });
        }
    }
}
