#ifndef ASSERTER_H
#define ASSERTER_H

#include <string>

struct Asserter {

  static void fail(const std::string message, const long lineNumber,
                   const std::string fileName);

  static void failIf(bool shouldFail, const std::string message,
                     const long lineNumber, const std::string fileName);
};

#endif
