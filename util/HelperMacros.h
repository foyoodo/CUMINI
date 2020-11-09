#ifndef HELPERMACROS_H
#define HELPERMACROS_H

#include "../include/Asserter.h"
#include "../include/TestAssert.h"
#include "../include/TestCaller.h"
#include "../include/TestFixture.h"
#include "../include/TestSuite.h"

#define CUMINI_TEST_SUITE(ATestFixtureType)                                    \
  using TestFixtureType = ATestFixtureType;                                    \
                                                                               \
public:                                                                        \
  static TestSuite *suite() {                                                  \
    TestSuite *testSuite = new TestSuite(#ATestFixtureType);                   \
    using Caller = TestCaller<TestFixtureType>;

#define CUMINI_TEST(testMethod)                                                \
  testSuite->addTest(new Caller(#testMethod, &TestFixtureType::testMethod))

#define CUMINI_TEST_SUITE_END()                                                \
  return testSuite;                                                            \
  }

// ! Fix me: can not create a new single testFunction, caused by the new
// TestCaller.
//
#define CUMINI_TEST_NEW_TESTFUNCTION(testFunction) \
  new TestCaller<TestFixture>(#testFunction, testFunction)

#endif
