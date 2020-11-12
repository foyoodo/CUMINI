#include "Triangle.h"

#include <climits>

Triangle::Triangle(long lborderA, long lborderB, long lborderC)
    : lborderA(lborderA), lborderB(lborderB), lborderC(lborderC) {}

Triangle::~Triangle() = default;

bool Triangle::isTriangle() const {
  bool isTriangle = false;

  // check boundary
  if ((lborderA > 0 && lborderA <= LONG_MAX) &&
      (lborderB > 0 && lborderB <= LONG_MAX) &&
      (lborderC > 0 && lborderC <= LONG_MAX)) {

    // check if subtraction of two border larger than the third
    if (diffOfBorders(lborderA, lborderB) < lborderC &&
        diffOfBorders(lborderB, lborderC) < lborderA &&
        diffOfBorders(lborderC, lborderA) < lborderB) {
      isTriangle = true;
    }
  }
  return isTriangle;
}

std::string Triangle::getType() const {
  std::string strType = "Illegal";

  if (isTriangle()) {
    if (lborderA == lborderB && lborderB == lborderC) {
      strType = "Regular";
    } else if ((lborderA != lborderB) && (lborderB != lborderC) &&
               (lborderA != lborderC)) {
      strType = "Scalene";
    } else {
      strType = "Isosceles";
    }
  }

  return strType;
}

long Triangle::diffOfBorders(long a, long b) const {
  return (a > b) ? (a - b) : (b - a);
}

long *Triangle::getBorders() const {
  long *borders = new long[3];
  borders[0] = lborderA;
  borders[1] = lborderB;
  borders[2] = lborderC;
  return borders;
}
