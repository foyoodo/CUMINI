#include "../include/TestResultCollector.h"
#include "../include/TestFailure.h"

namespace CUMINI {

TestResultCollector::~TestResultCollector() {
  auto it = m_failures.begin();
  while (it != m_failures.end())
    delete *it++;
  m_failures.clear();
}

void TestResultCollector::addRunTest() { ++m_runTests; }

void TestResultCollector::addFailure(const TestFailure &failure) {
  if (m_success)
    m_success = false;
  if (failure.isError())
    ++m_testErrors;
  m_failures.push_back(failure.clone());
}

const TestResultCollector::TestFailures &TestResultCollector::failures() const {
  return m_failures;
}

int TestResultCollector::runTests() const { return m_runTests; }

int TestResultCollector::testErrors() const { return m_testErrors; }

int TestResultCollector::testFailures() const {
  return m_failures.size() - m_testErrors;
}

bool TestResultCollector::wasSuccessful() const { return m_success; }

} // namespace CUMINI
