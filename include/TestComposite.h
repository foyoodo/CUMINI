#ifndef TESTCOMPOSITE_H
#define TESTCOMPOSITE_H

#include "Test.h"

#include <string>

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

#endif // TESTCOMPOSITE_H
