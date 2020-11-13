#ifndef CUMINI_TESTRUNNER_H
#define CUMINI_TESTRUNNER_H

namespace CUMINI {

class Test;
class TestResult;
class TestSuite;

class TestRunner {
public:
  TestRunner();

  virtual ~TestRunner();

  virtual void addTest(Test *test);

  virtual void run(TestResult *result);

  int getChildTestCount() const;

protected:
  TestSuite *suite;

private:
  TestRunner(const TestRunner &another);
  TestRunner &operator=(TestRunner &another);
};

} // namespace CUMINI

#endif
