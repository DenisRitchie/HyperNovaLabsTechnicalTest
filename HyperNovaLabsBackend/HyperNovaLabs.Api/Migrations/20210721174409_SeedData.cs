using System;
using Microsoft.EntityFrameworkCore.Migrations;

namespace HyperNovaLabs.Api.Migrations
{
    public partial class SeedData : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.InsertData(
                table: "Bill",
                columns: new[] { "Id", "ApprovedBy", "Concept", "DateFrom", "DateTo", "EmployeeIdentification" },
                values: new object[] { 1L, "Raúl Campesino", "Pago Mensual", new DateTime(2021, 7, 1, 0, 0, 0, 0, DateTimeKind.Unspecified), new DateTime(2021, 7, 30, 0, 0, 0, 0, DateTimeKind.Unspecified), "12-00440-0" });

            migrationBuilder.InsertData(
                table: "BillDescription",
                columns: new[] { "Id", "BillId", "Date", "Description", "Price", "Quantity" },
                values: new object[] { 1L, 1L, new DateTime(2021, 7, 10, 0, 0, 0, 0, DateTimeKind.Unspecified), "Pago Proyecto de Micro-Servicios con C++ Grpc", 3500.0, 1 });

            migrationBuilder.InsertData(
                table: "BillDescription",
                columns: new[] { "Id", "BillId", "Date", "Description", "Price", "Quantity" },
                values: new object[] { 2L, 1L, new DateTime(2021, 7, 15, 0, 0, 0, 0, DateTimeKind.Unspecified), "Pago Proyecto WebAssembly con C++ Emscripten", 5000.0, 1 });

            migrationBuilder.InsertData(
                table: "BillDescription",
                columns: new[] { "Id", "BillId", "Date", "Description", "Price", "Quantity" },
                values: new object[] { 3L, 1L, new DateTime(2021, 7, 20, 0, 0, 0, 0, DateTimeKind.Unspecified), "Pago por Proyecto Backend en Asp .Net 5 y Grpc", 4000.0, 1 });
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DeleteData(
                table: "BillDescription",
                keyColumn: "Id",
                keyValue: 1L);

            migrationBuilder.DeleteData(
                table: "BillDescription",
                keyColumn: "Id",
                keyValue: 2L);

            migrationBuilder.DeleteData(
                table: "BillDescription",
                keyColumn: "Id",
                keyValue: 3L);

            migrationBuilder.DeleteData(
                table: "Bill",
                keyColumn: "Id",
                keyValue: 1L);
        }
    }
}
