#include "../include/TestSuite.h"

TestSuite::TestSuite(const std::string name) : TestComposite(name) {}

TestSuite::~TestSuite() {}

void TestSuite::addTest(Test *test) { tests.push_back(test); }

const std::vector<Test *> &TestSuite::getTests() const { return tests; }

Test *TestSuite::getChildTestAt(int index) const {
  checkInvalidIndex(index);
  return tests[index];
}

int TestSuite::getChildTestCount() const { return tests.size(); }

void TestSuite::deleteChildTests() {
  int childCount = getChildTestCount();
  Test *childTest;
  for (int i = 0; i < childCount; ++i) {
    childTest = getChildTestAt(i);
    if (childTest)
      delete getChildTestAt(i);
  }
  tests.clear();
}
