#include "../include/TestFailure.h"
#include "../include/TestListener.h"
#include "../include/TestResult.h"

TestResult::~TestResult() { listeners.clear(); }

void TestResult::addListener(TestListener *listener) {
  listeners.push_back(listener);
}

void TestResult::addFailure(Test *test, Exception *e) {
  TestFailure failure(test, e, false);
  addFailure(failure);
}

void TestResult::addError(Test *test, Exception *e) {
  TestFailure failure(test, e, true);
  addFailure(failure);
}

void TestResult::addFailure(const TestFailure &failure) {
  for (auto it = listeners.begin(); it != listeners.end(); ++it)
    (*it)->addFailure(failure);
}
