#include "../include/TestLeaf.h"

namespace CUMINI {

int TestLeaf::countTestCases() const { return 1; }

int TestLeaf::getChildTestCount() const { return 0; }

Test *TestLeaf::getChildTestAt(int index) const {
  checkInvalidIndex(index);
  return nullptr;
}

} // namespace CUMINI
