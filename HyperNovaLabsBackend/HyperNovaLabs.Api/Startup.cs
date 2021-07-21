namespace HyperNovaLabs.Api
{
    using HyperNovaLabs.Api.Models;
    using HyperNovaLabs.Api.Services;

    using Microsoft.AspNetCore.Builder;
    using Microsoft.AspNetCore.Hosting;
    using Microsoft.AspNetCore.Http;
    using Microsoft.EntityFrameworkCore;
    using Microsoft.Extensions.Configuration;
    using Microsoft.Extensions.DependencyInjection;
    using Microsoft.Extensions.Hosting;
    using Microsoft.OpenApi.Models;

    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Reflection;
    using System.Threading.Tasks;

    public class Startup
    {
        public Startup(IConfiguration Configuration)
        {
            this.Configuration = Configuration;
        }

        public IConfiguration Configuration { get; }

        public void ConfigureServices(IServiceCollection Services)
        {
            Services.AddDbContext<ExpenseReportContext>(Options =>
                Options.UseSqlServer(Configuration.GetConnectionString("DefaultConnection"),
                sqlServerOptionsAction: SqlOptions =>
                {
                    //Configuring Connection Resiliency: https://docs.microsoft.com/en-us/ef/core/miscellaneous/connection-resiliency

                    SqlOptions.MigrationsAssembly(typeof(Startup).GetTypeInfo().Assembly.GetName().Name);
                    SqlOptions.EnableRetryOnFailure(maxRetryCount: 15, maxRetryDelay: TimeSpan.FromSeconds(30), errorNumbersToAdd: null);
                }));

            Services.AddGrpcHttpApi();

            Services.AddSwaggerGen(Swagger =>
            {
                Swagger.SwaggerDoc("v1", new OpenApiInfo { Title = "gRPC HTTP API HyperNovaLabs", Version = "v1" });
            });

            Services.AddGrpcSwagger();
        }

        public void Configure(IApplicationBuilder App, IWebHostEnvironment Env)
        {
            if (Env.IsDevelopment())
            {
                App.UseDeveloperExceptionPage();
            }

            App.UseSwagger();
            App.UseSwaggerUI(Swagger =>
            {
                Swagger.SwaggerEndpoint("/swagger/v1/swagger.json", "gRPC HTTP API HyperNovaLabs V1");
            });

            App.UseRouting();

            App.UseEndpoints(Endpoints =>
            {
                Endpoints.MapGrpcService<EmployeeService>();
                Endpoints.MapGrpcService<ExpenseReportService>();
            });
        }
    }
}
