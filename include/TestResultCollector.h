#ifndef TESTRESULTCOLLECTOR_H
#define TESTRESULTCOLLECTOR_H

#include "TestListener.h"

#include <deque>

class TestFailure;

class TestResultCollector : public TestListener {
public:
  typedef std::deque<TestFailure *> TestFailures;

  virtual ~TestResultCollector();

  void addRunTest();
  void addFailure(const TestFailure &failure);

  const TestFailures &failures() const;

  virtual int runTests() const;
  virtual int testErrors() const;
  virtual int testFailures() const;

  virtual bool wasSuccessful() const;

private:
  TestFailures m_failures;
  // ! Fix me, cann't be default initialization
  int m_runTests = 0;
  int m_testErrors;
  bool m_success = true;
};

#endif
