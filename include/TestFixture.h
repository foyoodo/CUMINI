#ifndef CUMINI_TESTFIXTURE_H
#define CUMINI_TESTFIXTURE_H

namespace CUMINI {

class TestFixture {
public:
  virtual ~TestFixture() = default;

  virtual void setUp() {};

  virtual void tearDown() {};
};

} // namespace CUMINI

#endif
