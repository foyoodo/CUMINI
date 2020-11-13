#ifndef CUMINI_TESTSUITE_H
#define CUMINI_TESTSUITE_H

#include "TestComposite.h"

#include <vector>

namespace CUMINI {

class TestSuite : public TestComposite {
public:
  TestSuite(const std::string name = "");

  ~TestSuite();

  // Add the specified test to the suite.
  void addTest(Test *test);

  // Return the list of tests.
  const std::vector<Test *> &getTests() const;

  // Return the child test of the specified index.
  Test *getChildTestAt(int index) const;

  int getChildTestCount() const;

  virtual void deleteChildTests();

private:
  std::vector<Test *> tests;
};

} // namespace CUMINI

#endif
