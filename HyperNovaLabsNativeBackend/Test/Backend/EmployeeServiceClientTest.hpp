#ifndef __EMPLOYEESERVICECLIENTTEST_H__
#define __EMPLOYEESERVICECLIENTTEST_H__

#pragma once

#include <gtest/gtest.h>
#include "EmployeeServiceClient.hpp"

// https://google.github.io/googletest/primer.html

class EmployeeServiceClientTest : public ::testing::Test
{
protected:
  EmployeeServiceClientTest();
  ~EmployeeServiceClientTest() override;

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  // Code here will be called immediately after the constructor (right
  // before each test).
  void SetUp() override;

  // Code here will be called immediately after each test (right
  // before the destructor).
  void TearDown() override;

  EmployeeServiceClient m_EmployeeService;
};


#endif // __EMPLOYEESERVICECLIENTTEST_H__