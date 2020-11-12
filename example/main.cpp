#include "../include/Exception.h"
#include "../include/Test.h"
#include "../include/TestAssert.h"
#include "../include/TestCaller.h"
#include "../include/TestCase.h"
#include "../include/TestComposite.h"
#include "../include/TestFailure.h"
#include "../include/TestFixture.h"
#include "../include/TestLeaf.h"
#include "../include/TestResult.h"
#include "../include/TestResultCollector.h"
#include "../include/TestRunner.h"
#include "../include/TestSuite.h"
#include "../include/TextOutputter.h"
#include "../util/HelperMacros.h"

#include "Triangle.h"

#include <iostream>

using namespace std;

class TriangleTest : public TestFixture {
  CUMINI_TEST_SUITE(TriangleTest);
  CUMINI_TEST(isTriangle1);
  CUMINI_TEST_SUITE_END();

public:
  void isTriangle1() {
    Triangle triangle(1, 2, 1);

    CUMINI_ASSERT(Triangle::isTriangle(triangle));
  }
};

int main() {
  TestRunner runner;
  runner.addTest(TriangleTest::suite());

  TestResult result;
  TestResultCollector resultListener;
  result.addListener(&resultListener);
  runner.run(&result);

  TextOutputter outputter(&resultListener, cout);
  outputter.write();
  return 0;
}