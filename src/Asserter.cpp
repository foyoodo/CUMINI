#include "../include/Asserter.h"
#include "../include/Exception.h"

void Asserter::fail(const std::string message, const long lineNumber,
                    const std::string fileName) {
  throw Exception(message, lineNumber, fileName);
}

void Asserter::failIf(bool shouldFail, const std::string message,
                      const long lineNumber, const std::string fileName) {
  if (shouldFail)
    fail(message, lineNumber, fileName);
}

void Asserter::failNotEqual(std::string expected, std::string actual,
                            const long lineNumber, const std::string fileName) {
  std::string message = "Excepted: " + expected + "\n" + "Actual: " + actual;
  fail(message, lineNumber, fileName);
}

void Asserter::failNotLess(std::string expected, std::string actual,
                           const long lineNumber, const std::string fileName) {
  std::string message =
      "Expected less than: " + expected + "\n" + "Actual: " + actual;
  fail(message, lineNumber, fileName);
}

void Asserter::failNotLessEqual(std::string expected, std::string actual,
                                const long lineNumber,
                                const std::string fileName) {
  std::string message =
      "Expected less or equal than: " + expected + "\n" + "Actual: " + actual;
  fail(message, lineNumber, fileName);
}

void Asserter::failNotGreater(std::string expected, std::string actual,
                              const long lineNumber,
                              const std::string fileName) {
  std::string message =
      "Excepted greater than: " + expected + "\n" + "Actual: " + actual;
  fail(message, lineNumber, fileName);
}

void Asserter::failNotGreaterEqual(std::string expected, std::string actual,
                                   const long lineNumber,
                                   const std::string fileName) {
  std::string message = "Excepted greater or equal than: " + expected + "\n" +
                        "Actual: " + actual;
  fail(message, lineNumber, fileName);
}
