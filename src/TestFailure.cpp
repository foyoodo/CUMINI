#include "../include/TestFailure.h"
#include "../include/Exception.h"
#include "../include/Test.h"

namespace CUMINI {

TestFailure::TestFailure(Test *failedTest, Exception *thrownException,
                         bool isError)
    : m_failedTest(failedTest), m_thrownException(thrownException),
      m_isError(isError){};

TestFailure::~TestFailure() {}

Exception *TestFailure::thrownException() const { return m_thrownException; }

Test *TestFailure::failedTest() const { return m_failedTest; }

long TestFailure::lineNumber() const { return m_thrownException->lineNumber(); }

std::string TestFailure::fileName() const {
  return m_thrownException->fileName();
}

std::string TestFailure::failedTestName() const {
  return m_failedTest->getName();
}

bool TestFailure::isError() const { return m_isError; }

TestFailure *TestFailure::clone() const {
  return new TestFailure(m_failedTest, m_thrownException->clone(), m_isError);
}

} // namespace CUMINI
