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
  static CUMINI::TestSuite *suite() {                                          \
    CUMINI::TestSuite *testSuite = new CUMINI::TestSuite(#ATestFixtureType);   \
    using Caller = CUMINI::TestCaller<TestFixtureType>;

#define CUMINI_TEST(testMethod)                                                \
    testSuite->addTest(new Caller(#testMethod, &TestFixtureType::testMethod))

#define CUMINI_TEST_SUITE_END()                                                \
    return testSuite;                                                          \
  }

#define CUMINI_TEST_NEW_TESTFUNCTION(testFunction)                             \
  new CUMINI::TestCaller<CUMINI::TestFixture>(#testFunction, testFunction)

#endif
