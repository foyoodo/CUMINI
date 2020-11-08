#ifndef TESTLEAF_H
#define TESTLEAF_H

#include "Test.h"

class TestLeaf : public Test {
public:
  int countTestCases() const;

  int getChildTestCount() const;

  // Always throw std::out_of_range.
  Test *getChildTestAt(int index) const;
};

#endif
