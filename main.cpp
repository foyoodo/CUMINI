#include "include/Exception.h"
#include "include/Test.h"
#include "include/TestAssert.h"
#include "include/TestCaller.h"
#include "include/TestCase.h"
#include "include/TestComposite.h"
#include "include/TestFailure.h"
#include "include/TestFixture.h"
#include "include/TestLeaf.h"
#include "include/TestResult.h"
#include "include/TestResultCollector.h"
#include "include/TestRunner.h"
#include "include/TestSuite.h"
#include "include/TextOutputter.h"
#include "util/HelperMacros.h"

#include <iostream>

class SimpleTest : public TestFixture {
  CUMINI_TEST_SUITE(SimpleTest);
  CUMINI_TEST(testEqual);
  CUMINI_TEST(testLess);
  CUMINI_TEST(testLessEqual);
  CUMINI_TEST(testGreater);
  CUMINI_TEST(testGreaterEqual);
  CUMINI_TEST_SUITE_END();

public:
  void setUp() {
    // std::cout << "\n--- SimpleTest: unit start\n";
  }

  void tearDown() {
    // std::cout << "\n    SimpleTest: unit done ---\n";
  }

  void testEqual() {
    CUMINI_ASSERT_EQUAL(2, 2);
    CUMINI_ASSERT_EQUAL(2, 3);
  }

  void testLess() {
    CUMINI_ASSERT_LESS(2, 3);
  }

  void testLessEqual() {
    CUMINI_ASSERT_LESSEQUAL(2, 3);
  }

  void testGreater() {
    CUMINI_ASSERT_GREATER(3, 4);
  }

  void testGreaterEqual() {
    CUMINI_ASSERT_GREATEREQUAL(3, 4);
  }
};

void testAssert() {
  CUMINI_ASSERT(2 == 3);
}

int main() {
  TestRunner runner;
  runner.addTest(SimpleTest::suite());
  runner.addTest(CUMINI_TEST_NEW_TESTFUNCTION(testAssert)); // single function

  TestResult result;
  TestResultCollector resultListener;
  result.addListener(&resultListener);
  runner.run(&result);

  TextOutputter outputter(&resultListener, std::cout);
  outputter.write();

  return 0;
}
