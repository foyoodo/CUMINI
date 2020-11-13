#ifndef CUMINI_TRIANGLE_H
#define CUMINI_TRIANGLE_H

#include <string>

class Triangle {
public:
  Triangle(long lboardA = 0, long lboardB = 0, long lboardC = 0);

  ~Triangle();

  bool isTriangle() const;

  std::string getType() const;

  long diffOfBorders(long a, long b) const;

  long *getBorders() const;

  bool operator==(const Triangle &rhs) const;

protected:
  long lborderA;
  long lborderB;
  long lborderC;
};

#endif