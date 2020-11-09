#ifndef TESTASSERT_H
#define TESTASSERT_H

#include "Asserter.h"

#include <iostream>

template <class T> struct AssertionTraits {
  static bool equal(const T &x, const T &y) { return x == y; }

  static bool less(const T &x, const T &y) { return x < y; }

  static bool lessEqual(const T &x, const T &y) { return x <= y; }
};

template <class T>
void assertEqual(const T &expected, const T &actual, long lineNumber,
                 std::string message) {
  if (!AssertionTraits<T>::equal(actual, expected)) {
    Asserter::failNotEqual(std::to_string(expected), std::to_string(actual),
                           lineNumber, message);
  }
}

template <class T>
void assertLess(const T &expected, const T &actual, long lineNumber,
                const std::string message) {
  if (!AssertionTraits<T>::less(actual, expected)) {
    Asserter::failNotLess(std::to_string(expected), std::to_string(actual),
                          lineNumber, message);
  }
}

template <class T>
void assertLessEqual(const T &expected, const T &actual, long lineNumber,
                     const std::string message) {
  if (!AssertionTraits<T>::lessEqual(actual, expected)) {
    Asserter::failNotLessEqual(std::to_string(expected), std::to_string(actual),
                               lineNumber, message);
  }
}

template <class T>
void assertGreater(const T &expected, const T &actual, long lineNumber,
                   const std::string message) {
  if (!AssertionTraits<T>::less(expected, actual)) {
    Asserter::failNotGreater(std::to_string(expected), std::to_string(actual),
                             lineNumber, message);
  }
}

template <class T>
void assertGreaterEqual(const T &expected, const T &actual, long lineNumber,
                        const std::string message) {
  if (!AssertionTraits<T>::lessEqual(expected, actual)) {
    Asserter::failNotGreaterEqual(std::to_string(expected),
                                  std::to_string(actual), lineNumber, message);
  }
}

#define CUMINI_ASSERT(condation)                                               \
  (Asserter::failIf(!(condation), "assertion failed, Exception: " #condation,  \
                    __LINE__, __FILE__))

#define CUMINI_ASSERT_EQUAL(expected, actual)                                  \
  assertEqual(expected, actual, __LINE__, __FILE__);

#define CUMINI_ASSERT_LESS(expected, actual)                                   \
  assertLess(expected, actual, __LINE__, __FILE__);

#define CUMINI_ASSERT_LESSEQUAL(expected, actual)                              \
  assertLessEqual(expected, actual, __LINE__, __FILE__);

#define CUMINI_ASSERT_GREATER(expected, actual)                                \
  assertGreater(expected, actual, __LINE__, __FILE__);

#define CUMINI_ASSERT_GREATEREQUAL(expected, actual)                           \
  assertGreaterEqual(expected, actual, __LINE__, __FILE__);

#endif
