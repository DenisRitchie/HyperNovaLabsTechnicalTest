#ifndef __MOCKEMPLOYEESTORE_H__
#define __MOCKEMPLOYEESTORE_H__

#include <vector>
#include <memory>
#include <string>
#include <string_view>
#include <algorithm>
#include <ranges>
#include <optional>

#include "Models/Employee.pb.h"

namespace HyperNovaLabs::Native::Backend::Mock
{
  struct Employee
  {
    Employee(
        const std::string_view identification,
        const std::string_view name,
        const std::string_view department,
        const std::string_view position,
        const std::string_view supervisor) noexcept
        : Identification{identification}, Name{name}, Department{department}, Position{position}, Supervisor{supervisor}
    {
    }

    Employee() = default;
    Employee(const Employee &) = default;
    Employee(Employee &&) = default;

    std::string Identification;
    std::string Name;
    std::string Department;
    std::string Position;
    std::string Supervisor;
  };

  class MockEmployeeStore final : private std::vector<Employee>
  {
    using base = std::vector<Employee>;

  public:
    class Value;
    class Iterator;

    void Add(const ::HyperNovaLabs::Api::Protos::Models::Employee &employee) noexcept
    {
      this->emplace_back(
          employee.identification(), employee.name(), employee.department(), employee.position(), employee.supervisor());
    }

    std::optional<::HyperNovaLabs::Api::Protos::Models::Employee> Find(const std::string_view identification) const noexcept
    {
      const_iterator result = std::find_if(base::cbegin(), base::cend(), [&identification](const Employee& value)
      { 
        return value.Identification == identification;
      });

      if (result != base::cend())
      {
        std::optional<::HyperNovaLabs::Api::Protos::Models::Employee> result_value{ std::in_place };
        Value(const_cast<Employee*>(result.operator->())).CopyTo(result_value.operator->());
        return std::move(result_value);
      }

      return std::nullopt;
    }

    Iterator begin() { return {*this, base::begin()}; }

    Iterator end() { return {*this, base::end()}; }

    class Value
    {
      friend class Iterator;

    public:
      Value() = default;
      Value(Employee *employee) : m_Employee{ employee } { }

      void CopyTo(::HyperNovaLabs::Api::Protos::Models::Employee *out) const noexcept
      {
        out->set_identification(m_Employee->Identification);
        out->set_name(m_Employee->Name);
        out->set_department(m_Employee->Department);
        out->set_position(m_Employee->Position);
        out->set_supervisor(m_Employee->Supervisor);
      }

      Employee *operator->() const noexcept
      {
        return m_Employee;
      }

    private:
      mutable Employee *m_Employee;
    };

    class Iterator
    {
    public:
      MockEmployeeStore &m_Store;
      MockEmployeeStore::iterator m_Iterator;
      Value m_Value;

      Iterator(MockEmployeeStore &store, MockEmployeeStore::iterator iterator) noexcept
          : m_Store{store}, m_Iterator{iterator}
      {
      }

      const Value &operator*() const noexcept
      {
        m_Value.m_Employee = m_Iterator.operator->();
        return m_Value;
      }

      const Value *operator->() const noexcept
      {
        m_Value.m_Employee = m_Iterator.operator->();
        return &m_Value;
      }

      inline Iterator &operator++() noexcept
      {
        ++m_Iterator;
        return *this;
      }

      inline bool operator!=(const Iterator &iterator) const noexcept
      {
        return this->m_Iterator != iterator.m_Iterator;
      }
    };
  };
}

#endif // __MOCKEMPLOYEESTORE_H__