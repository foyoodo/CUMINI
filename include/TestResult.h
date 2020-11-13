#ifndef CUMINI_TESTRESULT_H
#define CUMINI_TESTRESULT_H

#include <deque>

namespace CUMINI {

class Exception;
class Test;
class TestFailure;
class TestListener;

class TestResult {
public:
  virtual ~TestResult();

  virtual void addListener(TestListener *listener);

  virtual void addRunTest();

  virtual void addFailure(Test *test, Exception *e);

  virtual void addError(Test *test, Exception *e);

protected:
  void addFailure(const TestFailure &failure);

protected:
  std::deque<TestListener *> listeners;
};

} // namespace CUMINI

#endif
