#ifndef CUMINI_TESTLEAF_H
#define CUMINI_TESTLEAF_H

#include "Test.h"

namespace CUMINI {

class TestLeaf : public Test {
public:
  int countTestCases() const;

  int getChildTestCount() const;

  // Always throw std::out_of_range.
  Test *getChildTestAt(int index) const;
};

} // namespace CUMINI

#endif
