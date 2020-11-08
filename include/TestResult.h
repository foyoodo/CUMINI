#ifndef TESTRESULT_H
#define TESTRESULT_H

#include <deque>

class Exception;
class Test;
class TestFailure;
class TestListener;

class TestResult {
public:
  virtual ~TestResult();

  virtual void addListener(TestListener *listener);

  virtual void addFailure(Test *test, Exception *e);

  virtual void addError(Test *test, Exception *e);

protected:
  void addFailure(const TestFailure &failure);

protected:
  std::deque<TestListener *> listeners;
};

#endif
