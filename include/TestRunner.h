#ifndef TESTRUNNER_H
#define TESTRUNNER_H

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

#endif
