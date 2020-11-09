#include "../include/TestCase.h"
#include "../include/Exception.h"
#include "../include/TestResult.h"

#include <exception>
#include <iostream>

TestCase::TestCase(const std::string &name) : name(name) {}

TestCase::~TestCase() = default;

void TestCase::run(TestResult *result) {
  try {
    setUp();
    try {
      runTest();
      result->addRunTest();
    } catch (Exception &e) {
      result->addFailure(this, e.clone());
    } catch (std::exception &e) {
      result->addError(this, new Exception("uncaught std::exception"));
    } catch (...) {
      result->addError(this, new Exception("uncaught unknown exception"));
    }
    try {
      tearDown();
    } catch (...) {
      result->addError(this, new Exception("tearDown() failed"));
    }
  } catch (...) {
    result->addError(this, new Exception("setUp() failed"));
  }
}

std::string TestCase::getName() const { return name; }
