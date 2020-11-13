#ifndef ASSERTER_H
#define ASSERTER_H

#include <string>

namespace CUMINI {

struct Asserter {

  static void fail(const std::string message, const long lineNumber,
                   const std::string fileName);

  static void failIf(bool shouldFail, const std::string message,
                     const long lineNumber, const std::string fileName);

  static void failNotEqual(std::string expected, std::string actual,
                           const long lineNumber, const std::string fileName);

  static void failNotLess(std::string expected, std::string actual,
                          const long lineNumber, const std::string fileName);

  static void failNotLessEqual(std::string expected, std::string actual,
                               const long lineNumber,
                               const std::string fileName);

  static void failNotGreater(std::string expected, std::string actual,
                             const long lineNumber, const std::string fileName);

  static void failNotGreaterEqual(std::string expected, std::string actual,
                                  const long lineNumber,
                                  const std::string fileName);
};

} // namespace CUMINI

#endif
