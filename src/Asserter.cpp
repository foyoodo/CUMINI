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
