#ifndef CUMINI_TEST_H
#define CUMINI_TEST_H

#include <string>

namespace CUMINI {

class TestResult;

class Test {
public:
  virtual ~Test();

  // Run the test and collect results.
  virtual void run(TestResult *result) = 0;

  // Return the number of test cases.
  virtual int countTestCases() const = 0;

  // Return the number of direct child of the test.
  virtual int getChildTestCount() const = 0;

  // Return the child test of the specified index.
  virtual Test *getChildTestAt(int index) const = 0;

  // Return the test name.
  virtual std::string getName() const = 0;

protected:
  // Throws an exception if the specified index is invalid.
  virtual void checkInvalidIndex(int index) const;
};

} // namespace CUMINI

#endif // CUMINI_TEST_H
