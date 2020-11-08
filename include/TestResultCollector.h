#ifndef TESTRESULTCOLLECTOR_H
#define TESTRESULTCOLLECTOR_H

#include "TestListener.h"

#include <deque>

class TestFailure;

class TestResultCollector : public TestListener {
public:
  typedef std::deque<TestFailure *> TestFailures;

  virtual ~TestResultCollector();

  void addFailure(const TestFailure &failure);

  const TestFailures &getFailures() const;

private:
  TestFailures failures;
  int testErrors;
};

#endif
