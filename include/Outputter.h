#ifndef OUTPUTTER_H
#define OUTPUTTER_H

namespace CUMINI {

class Outputter {
public:
  virtual ~Outputter() = default;

  virtual void write() = 0;
};

} // namespace CUMINI

#endif
