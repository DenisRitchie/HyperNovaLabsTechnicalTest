using Microsoft.EntityFrameworkCore.Migrations;

namespace HyperNovaLabs.Api.Migrations
{
    public partial class EmployeeSeedData : Migration
    {
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.InsertData(
                table: "Employee",
                columns: new[] { "Identification", "Department", "Name", "Position", "Supervisor" },
                values: new object[] { "12-00440-0", "Desarrollo", "Denis West", "Desarrollador C++", "N/A" });

            migrationBuilder.InsertData(
                table: "Employee",
                columns: new[] { "Identification", "Department", "Name", "Position", "Supervisor" },
                values: new object[] { "12-00441-0", "Ventas", "Darwin Seaz", "Ejecutivo de Ventas", "Denis West" });
        }

        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DeleteData(
                table: "Employee",
                keyColumn: "Identification",
                keyValue: "12-00440-0");

            migrationBuilder.DeleteData(
                table: "Employee",
                keyColumn: "Identification",
                keyValue: "12-00441-0");
        }
    }
}
