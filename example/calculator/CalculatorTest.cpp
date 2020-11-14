#include "../../include/TestAssert.h"
#include "../../include/TestCase.h"
#include "../../include/TestResult.h"
#include "../../include/TestResultCollector.h"
#include "../../include/TestRunner.h"
#include "../../include/TextOutputter.h"

#include "Calculator.h"

#include <iostream>

class CalculatorTest : public CUMINI::TestCase {
public:
  void runTest() {
    CUMINI_ASSERT_EQUAL(5, Calculator::add(2, 3));
    CUMINI_ASSERT_EQUAL(5, Calculator::sub(8, 3));
    CUMINI_ASSERT_EQUAL(6, Calculator::mul(3, 2));
    CUMINI_ASSERT_EQUAL(3, Calculator::div(6, 2));
  }
};

int main() {
  CUMINI::TestRunner runner;
  runner.addTest(new CalculatorTest);

  CUMINI::TestResult result;
  CUMINI::TestResultCollector resultListener;
  result.addListener(&resultListener);
  runner.run(&result);

  CUMINI::TextOutputter outputter(&resultListener, std::cout);
  outputter.write();
  return 0;
}
