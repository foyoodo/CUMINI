#ifndef TESTFIXTURE_H
#define TESTFIXTURE_H

namespace CUMINI {

class TestFixture {
public:
  virtual ~TestFixture() = default;

  virtual void setUp() {};

  virtual void tearDown() {};
};

} // namespace CUMINI

#endif
