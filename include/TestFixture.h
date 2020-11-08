#ifndef TESTFIXTURE_H
#define TESTFIXTURE_H

class TestFixture {
public:
  virtual ~TestFixture() = default;

  virtual void setUp() {};

  virtual void tearDown() {};
};

#endif
