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
#include "util/HelperMacros.h"
#include "include/TextOutputter.h"

#include <iostream>
#include <string>

using namespace std;

class SimpleTest : public TestFixture {
  CUMINI_TEST_SUITE(SimpleTest);
  CUMINI_TEST(test1);
  CUMINI_TEST(test2);
  CUMINI_TEST_SUITE_END();

public:
  void setUp() { cout << "--- SimpleTest setUp ---\n" << endl; }
  void tearDown() { cout << "\n--- SimpleTest tearDown ---\n" << endl; }

  void test1() {
    cout << "SimpleTest: method test1: succeed!" << endl;
    CUMINI_ASSERT(2 == 3);
    CUMINI_ASSERT(4 == 3);
    CUMINI_ASSERT_EQUAL(3, 2);
    CUMINI_ASSERT_LESS(2, 3);
    CUMINI_ASSERT_LESSEQUAL(2, 3);
    CUMINI_ASSERT_GREATER(3, 2);
    CUMINI_ASSERT_GREATEREQUAL(3, 2);
  }
  void test2() {
    CUMINI_ASSERT(2 == 3);
    cout << "SimpleTest: method test2: succeed!" << endl;
  }
};

class AnTest : public TestFixture {
  CUMINI_TEST_SUITE(AnTest);
  CUMINI_TEST(test1);
  CUMINI_TEST(test2);
  CUMINI_TEST_SUITE_END();

public:
  void setUp() { cout << "--- AnTest setUp ---\n" << endl; }
  void tearDown() { cout << "\n--- AnTest tearDown ---\n" << endl; }

  void test1() { cout << "AnTest: method test1: succeed!" << endl; }
  void test2() { cout << "AnTest: method test2: succeed!" << endl; }
};

int printSuccess() {
  cout << "printSuccess" << endl;
  return 0;
}

int main() {
  TestRunner runner;
  runner.addTest(SimpleTest::suite());
  runner.addTest(AnTest::suite());
  runner.addTest(CUMINI_TEST_NEW_TESTFUNCTION(printSuccess));
  cout << runner.getChildTestCount() << endl;

  TestResult result;
  TestResultCollector resultListener;
  result.addListener(&resultListener);
  runner.run(&result);

  TextOutputter outputter(&resultListener, cout);
  outputter.printFailures();
  
  return 0;
}