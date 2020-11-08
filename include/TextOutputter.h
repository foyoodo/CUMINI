#ifndef TEXTOUTPUTTER_H
#define TEXTOUTPUTTER_H

#include "Outputter.h"

#include <ostream>

class TestFailure;
class TestResult;
class TestResultCollector;

class TextOutputter : public Outputter {
public:
  TextOutputter(TestResultCollector *result, std::ostream &out);

  virtual ~TextOutputter();

  void write();

  virtual void printFailures();

protected:
  virtual void printFailure(TestFailure *failure, int failureNumber);

protected:
  TestResultCollector *result;
  std::ostream &out;
};

#endif
