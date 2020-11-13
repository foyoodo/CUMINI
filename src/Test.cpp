#include "../include/Test.h"

#include <stdexcept>

namespace CUMINI {

Test::~Test() {}

void Test::checkInvalidIndex(int index) const {
  if (index < 0 || index >= getChildTestCount())
    throw std::out_of_range("Test::checkInvalidIndex(): invalid index");
}

} // namespace CUMINI
