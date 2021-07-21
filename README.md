# HyperNovaLabs Technical Test

## Pasos para correr el proyecto localmente

1. Instalar Docker Desktop :point_right: [Descargar](https://www.docker.com/products/docker-desktop)
2. Instalar .Net 5. Viene activado por defecto con *Visual Studio 2019*.
2. Cambiar el directorio de trabajo a la carpeta: ***&lt;Path&gt;\HyperNovaLabsTechnicalTest\HyperNovaLabsBackend\HyperNovaLabs.Api***
   1. Ejecutar los siguentes comandos:
      * *dotnet tool install --global dotnet-ef*
      * *dotnet tool update --global dotnet-ef*
      * **(No Ejecutar Este Comando)** *dotnet ef migrations add InitialCreate*
      * Abrir la solución e inicar el proyecto: ***Docker-Compose***
        - *dotnet ef database update --connection **"Server=host.docker.internal,5433;Initial Catalog=HyperNovaLabs.Api.ExpenseReport.Db;User Id=sa;Password=Pass@word"***


## Tecnologías usadas en el Proyecto

1. Frontend **(WebAssembly)**: 
   * Emscripten :point_right: [Visitar](https://emscripten.org/)
     - Lenguajes de Programación
       * C++
       * C#
     - Lenguaje de Marcado
       * Xaml
     - Lenguaje de Definición de Interfaces
       * Protobuf
     - Editores
       * Visual Studio Code
       * Visual Studio 2019
       * Blend For Visual Studio 2019
     - Herramientas de Compilación
       * CMake
       * Docker
     - Frameworks
       * NoesisGUI :point_right: [Visitar](https://noesisengine.com/)
       * C++ Grpc :point_right: [Visitar](https://grpc.io/)
2. Backend **(Asp.Net Core)**
   * .Net 5 :point_right: [Visitar](https://dotnet.microsoft.com/download/dotnet/5.0)
     - Lenguaje de Programación
       * C#
     - Lenguaje de Definición de Interfaces
       * Protobuf
     - Editores
       * Visual Studio 2019
     - Herramientas de Compilación
       * MSBuild
       * Docker-Compose
     - Frameworks
       * C# Grpc

## Puntos de Accesos

### Backend

El Backend esta realizado mediante llamadas a procedimientos remotos.
Se le ha habilitado compatibilidad mediante Rest Api.

Los archivos de extensión ***.proto*** especifican el modelo interno del api.


1. Vista Swagger: http://localhost:5785/swagger/index.html

![Image of Yaktocat](Images/ExpenseReportApi.png)

2. GET: /api/employee
   * Obtiene una lista de todos los empleados.

3. POST: /api/employee
   * Crea un nuevo empleado.

4. GET: /api/employee/{identification}
   * Obtiene un empleado mediante una identificación.

5. DELETE: /api/employee/{identification}
   * Borra un empleado mediante su identificación.

6. PATH: /api/employee/{employee.identification}
   * Actualiza los datos de un empleado.

7. GET: /api/employee/{identification}/bills
   * Obtiene todas las facturas de un empleado existente.

8. GET: /api/bill
   * Obtiene una lista de todas las facturas.

9. GET: /api/bill/{bill_id}
   * Obtiene una factura por si Id.

10. POST: /api/bill
    * Crea una nueva factura.

### Frontend

El parte visual del proyecto está escrita en C++ mediante WebAssembly.

Url :point_right: http://localhost:5965/

El frontend aun esta incompleto, hay muchos cambios que aun no se ha subido.

Próximamente se subirá el ejemplo completo del frontend.