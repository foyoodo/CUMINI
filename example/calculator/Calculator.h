#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
  static int add(int x, int y) { return x + y; }

  static int sub(int x, int y) { return x - y; }

  static int mul(int x, int y) { return x / y; /* wrong */ }

  static int div(int x, int y) { return x / y; }
};

#endif