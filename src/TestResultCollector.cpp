#include "../include/TestFailure.h"
#include "../include/TestResultCollector.h"

TestResultCollector::~TestResultCollector() {
  auto it = failures.begin();
  while (it != failures.end())
    delete *it++;
  failures.clear();
}

void TestResultCollector::addFailure(const TestFailure &failure) {
  if (failure.isError())
    ++testErrors;
  failures.push_back(failure.clone());
}

const TestResultCollector::TestFailures &TestResultCollector::getFailures() const {
  return failures;
}
