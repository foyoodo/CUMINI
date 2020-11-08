#ifndef OUTPUTTER_H
#define OUTPUTTER_H

class Outputter {
public:
  virtual ~Outputter() = default;

  virtual void write() = 0;
};

#endif
