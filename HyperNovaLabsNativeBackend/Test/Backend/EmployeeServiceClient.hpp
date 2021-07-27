#ifndef __EMPLOYEESERVICECLIENT_H__
#define __EMPLOYEESERVICECLIENT_H__

#pragma once

#include "gtest/gtest.h"
#include "Models/Employee.pb.h"

// https://google.github.io/googletest/primer.html

class EmployeeServiceClientTest : public ::testing::Test
{
protected:
  EmployeeServiceClientTest();
  virtual ~EmployeeServiceClientTest();

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  // Code here will be called immediately after the constructor (right
  // before each test).
  void SetUp() override;

  // Code here will be called immediately after each test (right
  // before the destructor).
  void TearDown() override;
};

#endif // __EMPLOYEESERVICECLIENT_H__