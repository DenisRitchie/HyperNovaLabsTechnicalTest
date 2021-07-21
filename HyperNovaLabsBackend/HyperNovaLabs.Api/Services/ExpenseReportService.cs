namespace HyperNovaLabs.Api.Services
{
    using Google.Protobuf.WellKnownTypes;

    using Grpc.Core;

    using HyperNovaLabs.Api.Models;
    using HyperNovaLabs.Api.Protos;

    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Threading.Tasks;

    public class ExpenseReportService : Protos.Services.ExpenseReportService.ExpenseReportServiceBase
    {
        private readonly ExpenseReportContext Database;

        public ExpenseReportService(ExpenseReportContext Context)
        {
            Database = Context;
        }
    }
}
