#include "Triangle.h"

#include <climits>

Triangle::Triangle(long lborderA, long lborderB, long lborderC)
    : lborderA(lborderA), lborderB(lborderB), lborderC(lborderC) {}

Triangle::~Triangle() = default;

bool Triangle::isTriangle(Triangle &triangle) {
  bool isTriangle = false;

  // check boundary
  if ((triangle.lborderA > 0 && triangle.lborderA <= LONG_MAX) &&
      (triangle.lborderB > 0 && triangle.lborderB <= LONG_MAX) &&
      (triangle.lborderC > 0 && triangle.lborderC <= LONG_MAX)) {

    // check if subtraction of two border larger than the third
    if (diffOfBorders(triangle.lborderA, triangle.lborderB) <
            triangle.lborderC &&
        diffOfBorders(triangle.lborderB, triangle.lborderC) <
            triangle.lborderA &&
        diffOfBorders(triangle.lborderC, triangle.lborderA) <
            triangle.lborderB) {
      isTriangle = true;
    }
  }
  return isTriangle;
}

long Triangle::diffOfBorders(long a, long b) {
  return (a > b) ? (a - b) : (b - a);
}

long *Triangle::getBorders() const {
  long *borders = new long[3];
  borders[0] = this->lborderA;
  borders[1] = this->lborderB;
  borders[2] = this->lborderC;
  return borders;
}
