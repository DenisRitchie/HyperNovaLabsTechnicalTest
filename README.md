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
