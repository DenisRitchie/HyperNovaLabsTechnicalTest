namespace HyperNovaLabs.Api
{
    using HyperNovaLabs.Api.Services;

    using Microsoft.AspNetCore.Builder;
    using Microsoft.AspNetCore.Hosting;
    using Microsoft.AspNetCore.Http;
    using Microsoft.Extensions.DependencyInjection;
    using Microsoft.Extensions.Hosting;
    using Microsoft.OpenApi.Models;

    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Threading.Tasks;

    public class Startup
    {
        public void ConfigureServices(IServiceCollection Services)
        {
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
                Endpoints.MapGrpcService<ExpenseReportService>();
            });
        }
    }
}
