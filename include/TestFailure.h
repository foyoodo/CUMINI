#ifndef TESTFAILURE_H
#define TESTFAILURE_H

#include <string>

class Test;
class Exception;

class TestFailure {
public:
  TestFailure(Test *failedTest, Exception *thrownException, bool isError);

  ~TestFailure();

  Test *failedTest() const;

  Exception *thrownException() const;

  long lineNumber() const;

  std::string fileName() const;

  std::string failedTestName() const;

  bool isError() const;

  TestFailure *clone() const;

private:
  Test *m_failedTest;
  Exception *m_thrownException;
  bool m_isError;
};

#endif
