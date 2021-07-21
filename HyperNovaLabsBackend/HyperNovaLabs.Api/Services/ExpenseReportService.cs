namespace HyperNovaLabs.Api.Services
{
    using Google.Protobuf.WellKnownTypes;

    using Grpc.Core;

    using HyperNovaLabs.Api.Protos;
    using HyperNovaLabs.Api.Extensions;
    using HyperNovaLabs.Api.Protos.Models;
    using HyperNovaLabs.Api.Protos.Services;

    using Microsoft.EntityFrameworkCore;

    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Threading.Tasks;

    public class ExpenseReportService : Protos.Services.ExpenseReportService.ExpenseReportServiceBase
    {
        private readonly Models.ExpenseReportContext Database;

        public ExpenseReportService(Models.ExpenseReportContext Context)
        {
            Database = Context;
        }

        public override Task<ListBillResponse> ListBill(Empty Request, ServerCallContext Context)
        {
            ListBillResponse Response = new();

            var Data = Database.Bills.Include(B => B.Employee).Include(B => B.BillDescriptions).RemoveIQueryable().Select(B => new Bill
            {
                Concept = B.Concept,
                DateFrom = Timestamp.FromDateTime(DateTime.SpecifyKind(B.DateFrom, DateTimeKind.Utc)),
                DateTo = Timestamp.FromDateTime(DateTime.SpecifyKind(B.DateTo, DateTimeKind.Utc)),
                ApprovedBy = B.ApprovedBy,
                Employee = new Employee
                {
                    Identification = B.Employee.Identification,
                    Department = B.Employee.Department,
                    Name = B.Employee.Name,
                    Supervisor = B.Employee.Supervisor,
                    Position = B.Employee.Position
                },
                BillDescriptions =
                {
                    B.BillDescriptions.Select(Bd => new BillDescription
                    {
                        Date = Timestamp.FromDateTime(DateTime.SpecifyKind(Bd.Date, DateTimeKind.Utc)),
                        Description = Bd.Description,
                        Price = Bd.Price,
                        Quantity = Bd.Quantity,
                        Total = Bd.Price * Bd.Quantity
                    })
                }
            });

            Response.Bills.AddRange(Data);

            return Task.FromResult(Response);
        }

        public override async Task<Bill> GetBill(GetBillRequest Request, ServerCallContext Context)
        {
            var Bills = await Database.Bills.Include(B => B.Employee).Include(B => B.BillDescriptions)
                .SingleOrDefaultAsync(B => B.Id == Request.BillId);

            if (Bills is not null)
            {
                return new Bill
                {
                    Concept = Bills.Concept,
                    DateFrom = Timestamp.FromDateTime(DateTime.SpecifyKind(Bills.DateFrom, DateTimeKind.Utc)),
                    DateTo = Timestamp.FromDateTime(DateTime.SpecifyKind(Bills.DateTo, DateTimeKind.Utc)),
                    ApprovedBy = Bills.ApprovedBy,
                    Employee = new Employee
                    {
                        Identification = Bills.Employee.Identification,
                        Department = Bills.Employee.Department,
                        Name = Bills.Employee.Name,
                        Supervisor = Bills.Employee.Supervisor,
                        Position = Bills.Employee.Position
                    },
                    BillDescriptions =
                    {
                        Bills.BillDescriptions.Select(Bd => new BillDescription
                        {
                            Date = Timestamp.FromDateTime(DateTime.SpecifyKind(Bd.Date, DateTimeKind.Utc)),
                            Description = Bd.Description,
                            Price = Bd.Price,
                            Quantity = Bd.Quantity,
                            Total = Bd.Price * Bd.Quantity
                        })
                    }
                };
            }

            return default;
        }

        public override async Task<CreateBillResponse> CreateBill(CreateBillResquest Request, ServerCallContext Context)
        {
            CreateBillResponse Response = new()
            {
                Bill = Request.Bill
            };

            try
            {
                var Model = await Database.Bills.AddAsync(new Models.Bill
                {
                    Concept = Request.Bill.Concept,
                    DateFrom = Request.Bill.DateFrom.ToDateTime(),
                    DateTo = Request.Bill.DateTo.ToDateTime(),
                    ApprovedBy = Request.Bill.ApprovedBy,
                    EmployeeIdentification = Request.Bill.Employee.Identification,
                    BillDescriptions = new HashSet<Models.BillDescription>
                    {
                        Request.Bill.BillDescriptions.Select(Bd => new Models.BillDescription
                        {
                            Date = Bd.Date.ToDateTime(),
                            Description = Bd.Description,
                            Price = Bd.Price,
                            Quantity = Bd.Quantity
                        })
                    }
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
    }
}
