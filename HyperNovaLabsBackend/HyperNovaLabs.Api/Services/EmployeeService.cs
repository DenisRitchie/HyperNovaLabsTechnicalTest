namespace HyperNovaLabs.Api.Services
{
    using Google.Protobuf.WellKnownTypes;

    using Grpc.Core;

    using HyperNovaLabs.Api.Protos.Models;
    using HyperNovaLabs.Api.Protos.Services;

    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Threading.Tasks;

    public class EmployeeService : Protos.Services.EmployeeService.EmployeeServiceBase
    {
        private readonly Models.ExpenseReportContext Database;

        public EmployeeService(Models.ExpenseReportContext Context)
        {
            Database = Context;
        }

        public override Task<ListEmployeeResponse> ListEmployee(Empty Request, ServerCallContext Context)
        {
            ListEmployeeResponse Response = new ListEmployeeResponse();

            var Data = Database.Employees.Select(E => new Employee
            {
                Name = E.Name,
                Identification = E.Identification,
                Department = E.Department,
                Position = E.Position,
                Supervisor = E.Supervisor
            });

            Response.Employees.AddRange(Data);

            return Task.FromResult(Response);
        }

        public override async Task<Employee> GetEmployee(GetEmployeeRequest Request, ServerCallContext Context)
        {
            var Employee = await Database.Employees.FindAsync(Request.Identification);

            return new Employee
            {
                Name = Employee.Name,
                Identification = Employee.Identification,
                Department = Employee.Department,
                Position = Employee.Position,
                Supervisor = Employee.Supervisor
            };
        }

        public override Task<Employee> CreateEmployee(CreateEmployeeRequest Request, ServerCallContext Context)
        {
            return base.CreateEmployee(Request, Context);
        }

        public override Task<Employee> UpdateEmployee(UpdateEmployeeRequest Request, ServerCallContext Context)
        {
            return base.UpdateEmployee(Request, Context);
        }

        public override Task<Empty> DeleteEmployee(DeleteEmployeeRequest Request, ServerCallContext Context)
        {
            return base.DeleteEmployee(Request, Context);
        }
    }
}
