#ifndef TESTLISTENER_H
#define TESTLISTENER_H

class TestFailure;

class TestListener {
public:
  virtual ~TestListener() = default;

  virtual void addRunTest() = 0;
  virtual void addFailure(const TestFailure &) = 0;
};

#endif
