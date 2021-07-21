namespace HyperNovaLabs.Api.Services
{
    using Google.Protobuf.WellKnownTypes;

    using Grpc.Core;

    using HyperNovaLabs.Api.Protos.Models;
    using HyperNovaLabs.Api.Protos.Services;

    using Microsoft.EntityFrameworkCore;

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
            ListEmployeeResponse Response = new();

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

            if (Employee is not null)
            {
                return new Employee
                {
                    Name = Employee.Name,
                    Identification = Employee.Identification,
                    Department = Employee.Department,
                    Position = Employee.Position,
                    Supervisor = Employee.Supervisor
                };
            }

            return default;
        }

        public override async Task<CreateEmployeeResponse> CreateEmployee(CreateEmployeeRequest Request, ServerCallContext Context)
        {
            CreateEmployeeResponse Response = new()
            {
                Employee = Request.Employee
            };

            try
            {
                var Employee = await Database.Employees.FindAsync(Request.Employee.Identification);

                if (Employee is not null)
                {
                    Response.HasError = true;
                    Response.Errors.Add("Un empleado con el mismo número de identificación ya esta registrado.");
                    return Response;
                }

                await Database.Employees.AddAsync(new Models.Employee
                {
                    Name = Request.Employee.Name,
                    Identification = Request.Employee.Identification,
                    Department = Request.Employee.Department,
                    Position = Request.Employee.Position,
                    Supervisor = Request.Employee.Supervisor
                });

                await Database.SaveChangesAsync();
            }
            catch (Exception Ex)
            {
                Response.HasError = true;

                while (Ex != null)
                {
                    Response.Errors.Add(Ex.Message);
                    Ex = Ex.InnerException;
                }
            }

            return Response;
        }

        public override async Task<UpdateEmployeeResponse> UpdateEmployee(UpdateEmployeeRequest Request, ServerCallContext Context)
        {
            UpdateEmployeeResponse Response = new()
            {
                Employee = Request.Employee
            };

            try
            {
                var Employee = await Database.Employees.FindAsync(Request.Employee.Identification);

                if (Employee is not null)
                {
                    Employee.Name = Request.Employee.Name;
                    Employee.Department = Request.Employee.Department;
                    Employee.Position = Request.Employee.Position;
                    Employee.Supervisor = Request.Employee.Supervisor;

                    Database.Employees.Update(Employee);
                    await Database.SaveChangesAsync();

                    Response.Success = true;
                    Response.Employee.Name = Employee.Name;
                    Response.Employee.Department = Employee.Department;
                    Response.Employee.Position = Employee.Position;
                    Response.Employee.Supervisor = Employee.Supervisor;
                }
                else
                {
                    Response.Errors.Add($"El empleado con el número de identificación \"{Request.Employee.Identification}\" no está registrado.");
                }
            }
            catch (Exception Ex)
            {
                while (Ex != null)
                {
                    Response.Errors.Add(Ex.Message);
                    Ex = Ex.InnerException;
                }
            }

            return Response;
        }

        public override async Task<DeleteEmployeeResponse> DeleteEmployee(DeleteEmployeeRequest Request, ServerCallContext Context)
        {
            DeleteEmployeeResponse Response = new();

            try
            {
                var Employee = await Database.Employees.FindAsync(Request.Identification);

                if (Employee is not null)
                {
                    Database.Employees.Remove(Employee);
                    await Database.SaveChangesAsync();

                    Response.Success = true;
                    Response.Employee = new Employee
                    {
                        Name = Employee.Name,
                        Identification = Employee.Identification,
                        Department = Employee.Department,
                        Position = Employee.Position,
                        Supervisor = Employee.Supervisor
                    };
                }
                else
                {
                    Response.Errors.Add($"El empleado con el número de identificación \"{Request.Identification}\" no está registrado.");
                }
            }
            catch (Exception Ex)
            {
                while (Ex != null)
                {
                    Response.Errors.Add(Ex.Message);
                    Ex = Ex.InnerException;
                }
            }

            return Response;
        }

        public override async Task<ListOfAnEmployeesBillResponse> ListOfAnEmployeeBills(ListOfAnEmployeesBillRequest Request, ServerCallContext Context)
        {
            ListOfAnEmployeesBillResponse Response = new();

            try
            {
                var Employee = await Database.Employees.Include(E => E.Bills).ThenInclude(B => B.BillDescriptions)
                    .SingleOrDefaultAsync(E => E.Identification == Request.Identification);

                if (Employee is not null)
                {
                    Response.Bills.Add(Employee.Bills.Select(B => new Bill
                    {
                        Concept = B.Concept,
                        ApprovedBy = B.ApprovedBy,
                        DateFrom = Timestamp.FromDateTime(DateTime.SpecifyKind(B.DateFrom, DateTimeKind.Utc)),
                        DateTo = Timestamp.FromDateTime(DateTime.SpecifyKind(B.DateTo, DateTimeKind.Utc)),
                        BillDescriptions =
                        {
                            B.BillDescriptions.Select(Bd => new BillDescription
                            {
                                Date = Timestamp.FromDateTime(DateTime.SpecifyKind(Bd.Date, DateTimeKind.Utc)),
                                Description = Bd.Description,
                                Price = Bd.Price,
                                Quantity = Bd.Quantity,
                                Total = Bd.Quantity * Bd.Price
                            })
                        }
                    }));

                    Response.Employee = new Employee
                    {
                        Name = Employee.Name,
                        Identification = Employee.Identification,
                        Department = Employee.Department,
                        Position = Employee.Position,
                        Supervisor = Employee.Supervisor
                    };

                    Response.Success = true;
                }
                else
                {
                    Response.Errors.Add($"El empleado con el número de identificación \"{Request.Identification}\" no está registrado.");
                }
            }
            catch (Exception Ex)
            {
                while (Ex != null)
                {
                    Response.Errors.Add(Ex.Message);
                    Ex = Ex.InnerException;
                }
            }

            return Response;
        }
    }
}
