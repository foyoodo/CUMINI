#include "../../include/TestResult.h"
#include "../../include/TestResultCollector.h"
#include "../../include/TestRunner.h"
#include "../../include/TextOutputter.h"
#include "../../util/HelperMacros.h"

#include "Triangle.h"

#include <iostream>

class TriangleTest : public TestFixture {
  CUMINI_TEST_SUITE(TriangleTest);
  CUMINI_TEST(triangle011);
  CUMINI_TEST(triangle121);
  CUMINI_TEST(triangle122);
  CUMINI_TEST(triangle222);
  CUMINI_TEST(triangle234);
  CUMINI_TEST(triangleEqual);
  CUMINI_TEST(triangleEqual2);
  CUMINI_TEST_SUITE_END();

public:
  void triangle011() {
    Triangle triangle(0, 1, 1);
    CUMINI_ASSERT(triangle.isTriangle());
    std::cout << "triangle011: " << triangle.getType() << std::endl;
  }

  void triangle121() {
    Triangle triangle(1, 2, 1);
    CUMINI_ASSERT(triangle.isTriangle());
    std::cout << "triangle121: " << triangle.getType() << std::endl;
  }

  void triangle122() {
    Triangle triangle(1, 2, 2);
    CUMINI_ASSERT(triangle.isTriangle());
    std::cout << "triangle122: " << triangle.getType() << std::endl;
  }

  void triangle222() {
    Triangle triangle(2, 2, 2);
    CUMINI_ASSERT(triangle.isTriangle());
    std::cout << "triangle222: " << triangle.getType() << std::endl;
  }

  void triangle234() {
    Triangle triangle(2, 3, 4);
    CUMINI_ASSERT(triangle.isTriangle());
    std::cout << "triangle234: " << triangle.getType() << std::endl;
  }

  void triangleEqual() {
    Triangle triangle1(2, 3, 4);
    Triangle triangle2(3, 2, 4);
    CUMINI_ASSERT(triangle1 == triangle2);
  }

  void triangleEqual2() {
    Triangle triangle1(2, 3, 4);
    Triangle triangle2(3, 3, 4);
    CUMINI_ASSERT(triangle1 == triangle2);
  }
};

int main() {
  TestRunner runner;
  runner.addTest(TriangleTest::suite());

  TestResult result;
  TestResultCollector resultListener;
  result.addListener(&resultListener);
  runner.run(&result);

  TextOutputter outputter(&resultListener, std::cout);
  outputter.write();
  return 0;
}
