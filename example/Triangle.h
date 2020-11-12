#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>

class Triangle {
public:
  Triangle(long lboardA = 0, long lboardB = 0, long lboardC = 0);

  ~Triangle();

  static bool isTriangle(Triangle &triangle);

  static std::string getType(Triangle &triangle);

  static long diffOfBorders(long a, long b);

  long *getBorders() const;

protected:
  long lborderA;
  long lborderB;
  long lborderC;
};

#endif