#include "../include/Exception.h"
#include "../include/TextOutputter.h"
#include "../include/TestFailure.h"
#include "../include/TestResult.h"
#include "../include/TestResultCollector.h"

TextOutputter::TextOutputter(TestResultCollector *result, std::ostream &out)
    : result(result), out(out) {}

TextOutputter::~TextOutputter() = default;

void TextOutputter::write() {
  printFailures();
}

void TextOutputter::printFailures() {
  auto it = result->getFailures().begin();
  int failureNumber = 1;
  while (it != result->getFailures().end()) {
    out << "\n";
    printFailure(*it++, failureNumber++);
  }
}

void TextOutputter::printFailure(TestFailure *failure, int failureNumber) {
  out << failureNumber << ") ";
  out << "test: " << failure->failedTestName();
  out << " (" << (failure->isError() ? "E" : "F") << ") ";
  out << "line: " << failure->lineNumber() << ' ' << failure->fileName();
  out << "\n" << failure->thrownException()->message() << "\n";
}
