namespace HyperNovaLabs.Api.Models
{
    using Microsoft.EntityFrameworkCore;

    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Threading.Tasks;

    public class ExpenseReportContext : DbContext
    {
        public ExpenseReportContext(DbContextOptions<ExpenseReportContext> Options) : base(Options)
        {
        }

        public DbSet<Employee> Employees { get; set; }

        public DbSet<Bill> Bills { get; set; }

        public DbSet<BillDescription> BillDescriptions { get; set; }

        protected override void OnModelCreating(ModelBuilder ModelBuilder)
        {
            ModelBuilder.Entity<Employee>(E =>
            {
                var Data = new Employee[]
                {
                    new Employee
                    {
                        Identification = "12-00440-0",
                        Name = "Denis West",
                        Department = "Desarrollo",
                        Supervisor = "N/A",
                        Position = "Desarrollador C++",
                    },

                    new Employee
                    {
                        Identification = "12-00441-0",
                        Name = "Darwin Seaz",
                        Department = "Ventas",
                        Supervisor = "Denis West",
                        Position = "Ejecutivo de Ventas",
                    }
                };

                E.HasData(Data);
            });

            ModelBuilder.Entity<Bill>(B =>
            {
                var Data = new Bill[]
                {
                    new Bill
                    {
                        Id = 1,
                        EmployeeIdentification = "12-00440-0",
                        Concept = "Pago Mensual",
                        DateFrom = new DateTime(2021, 7, 1),
                        DateTo = new DateTime(2021, 7, 30),
                        ApprovedBy = "Raúl Campesino",
                    }
                };

                B.HasData(Data);
            });

            ModelBuilder.Entity<BillDescription>(Bd =>
            {
                var Data = new BillDescription[]
                {
                    new BillDescription
                    {
                        Id = 1,
                        BillId = 1,
                        Date = new DateTime(2021, 7, 10),
                        Description = "Pago Proyecto de Micro-Servicios con C++ Grpc",
                        Quantity = 1,
                        Price = 3500,
                    },
                    new BillDescription
                    {
                        Id = 2,
                        BillId = 1,
                        Date = new DateTime(2021, 7, 15),
                        Description = "Pago Proyecto WebAssembly con C++ Emscripten",
                        Quantity = 1,
                        Price = 5000,
                    },
                    new BillDescription
                    {
                        Id = 3,
                        BillId = 1,
                        Date = new DateTime(2021, 7, 20),
                        Description = "Pago por Proyecto Backend en Asp .Net 5 y Grpc",
                        Quantity = 1,
                        Price = 4000,
                    },
                };

                Bd.HasData(Data);
            });
        }
    }
}
