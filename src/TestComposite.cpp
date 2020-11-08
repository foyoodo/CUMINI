#include "../include/TestComposite.h"

TestComposite::TestComposite(const std::string &name) : name(name) {}

TestComposite::~TestComposite() {}

void TestComposite::run(TestResult *result) {
  int childCount = getChildTestCount();
  for (int i = 0; i < childCount; ++i) {
    getChildTestAt(i)->run(result);
  }
}

int TestComposite::countTestCases() const {
  int count = 0;
  int childCount = getChildTestCount();
  for (int i = 0; i < childCount; ++i) {
    count += getChildTestAt(i)->countTestCases();
  }
  return count;
}

std::string TestComposite::getName() const { return name; }
