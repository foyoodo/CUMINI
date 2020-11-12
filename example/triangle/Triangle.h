#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>

class Triangle {
public:
  Triangle(long lboardA = 0, long lboardB = 0, long lboardC = 0);

  ~Triangle();

  bool isTriangle() const;

  std::string getType() const;

  long diffOfBorders(long a, long b) const;

  long *getBorders() const;

protected:
  long lborderA;
  long lborderB;
  long lborderC;
};

#endif