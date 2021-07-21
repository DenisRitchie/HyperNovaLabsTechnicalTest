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
        }
    }
}
