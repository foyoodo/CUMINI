#ifndef CUMINI_OUTPUTTER_H
#define CUMINI_OUTPUTTER_H

namespace CUMINI {

class Outputter {
public:
  virtual ~Outputter() = default;

  virtual void write() = 0;
};

} // namespace CUMINI

#endif
