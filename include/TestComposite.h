#ifndef CUMINI_TESTCOMPOSITE_H
#define CUMINI_TESTCOMPOSITE_H

#include "Test.h"

#include <string>

namespace CUMINI {

class TestResult;

class TestComposite : public Test {
public:
  TestComposite(const std::string &name = "");

  ~TestComposite();

  void run(TestResult *result);

  int countTestCases() const;

  virtual Test *getChildTestAt(int index) const = 0;

  std::string getName() const;

private:
  TestComposite(const TestComposite &another);
  TestComposite &operator=(const TestComposite &another);

private:
  const std::string name;
};

} // namespace CUMINI

#endif // CUMINI_TESTCOMPOSITE_H
