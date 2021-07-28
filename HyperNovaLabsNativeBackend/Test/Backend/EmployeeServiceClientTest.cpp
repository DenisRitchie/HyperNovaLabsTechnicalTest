#include "EmployeeServiceClientTest.hpp"

using namespace HyperNovaLabs::Native::Backend;

EmployeeServiceClientTest::EmployeeServiceClientTest()
    : m_EmployeeService(grpc::CreateChannel(GrpcServerInfo::ServerAddress.data(), grpc::InsecureChannelCredentials()))
{
}

EmployeeServiceClientTest::~EmployeeServiceClientTest()
{
}

void EmployeeServiceClientTest::SetUp()
{
  Employee employee;

  employee.set_identification("12-00440-0");
  employee.set_name("Denis West");
  employee.set_department("Ingeniería");
  employee.set_position("Desarrollador");
  employee.set_supervisor("Ninguno");
  m_EmployeeService.CreateEmployee(employee);

  employee.set_identification("12-80440-1");
  employee.set_name("Nubia West");
  employee.set_department("Madres");
  employee.set_position("Ama de Casa");
  employee.set_supervisor("Ninguno");
  m_EmployeeService.CreateEmployee(employee);

  employee.set_identification("22-00470-9");
  employee.set_name("Mariano Garcías");
  employee.set_department("Marketing");
  employee.set_position("Diseño Gráfico");
  employee.set_supervisor("Denis West");
  m_EmployeeService.CreateEmployee(employee);
}

void EmployeeServiceClientTest::TearDown()
{
}

TEST_F(EmployeeServiceClientTest, ListEmployee)
{
  auto employees = m_EmployeeService.ListEmployee();

  EXPECT_EQ(employees.size(), 3);

  for (int32_t index = 0; const auto &employee : employees)
  {
    std::cout << std::string(30, '-') << std::endl;
    std::cout << "Registro Id: "      << ++index << std::endl;
    std::cout << std::string(30, '-') << std::endl;
    std::cout << "Identificación: " << employee.identification() << std::endl;
    std::cout << "Nombre:         " << employee.name() << std::endl;
    std::cout << "Departamento:   " << employee.department() << std::endl;
    std::cout << "Posición:       " << employee.position() << std::endl;
    std::cout << "Supervisor:     " << employee.supervisor() << std::endl;
    std::cout << std::endl;
  }
}

TEST_F(EmployeeServiceClientTest, GetEmployee)
{
  constexpr std::string_view identification = "12-00440-0";

  auto employee = m_EmployeeService.GetEmployee(identification);

  EXPECT_TRUE(employee.has_value());

  if (employee.has_value())
  {
    std::cout << std::endl;
    std::cout << "Información Id: " << identification << std::endl;
    std::cout << "Identificación: " << employee->identification() << std::endl;
    std::cout << "Nombre:         " << employee->name() << std::endl;
    std::cout << "Departamento:   " << employee->department() << std::endl;
    std::cout << "Posición:       " << employee->position() << std::endl;
    std::cout << "Supervisor:     " << employee->supervisor() << std::endl;
    std::cout << std::endl;
  }
}

TEST_F(EmployeeServiceClientTest, CreateEmployee)
{
  Employee employee;

  employee.set_identification("12-00440-0");
  employee.set_name("Denis West");
  employee.set_department("Ingeniería");
  employee.set_position("Desarrollador");
  employee.set_supervisor("Ninguno");
  const auto &[value, success] = m_EmployeeService.CreateEmployee(employee);

  EXPECT_TRUE(success);
  EXPECT_TRUE(value.has_value());
  EXPECT_EQ(employee.identification(), value->identification());
  EXPECT_EQ(employee.name(), value->name());
  EXPECT_EQ(employee.department(), value->department());
  EXPECT_EQ(employee.position(), value->position());
  EXPECT_EQ(employee.supervisor(), value->supervisor());

  std::cout << std::endl;
  std::cout << "Nuevo Registro Id " << std::endl;
  std::cout << "Identificación:   " << value->identification() << std::endl;
  std::cout << "Nombre:           " << value->name() << std::endl;
  std::cout << "Departamento:     " << value->department() << std::endl;
  std::cout << "Posición:         " << value->position() << std::endl;
  std::cout << "Supervisor:       " << value->supervisor() << std::endl;
  std::cout << std::endl;
}
