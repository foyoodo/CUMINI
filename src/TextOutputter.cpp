#include "../include/TextOutputter.h"
#include "../include/Exception.h"
#include "../include/TestFailure.h"
#include "../include/TestResult.h"
#include "../include/TestResultCollector.h"

TextOutputter::TextOutputter(TestResultCollector *result, std::ostream &out)
    : result(result), out(out) {}

TextOutputter::~TextOutputter() = default;

void TextOutputter::write() {
  printHeader();
  if (!result->wasSuccessful())
    printFailures();
}

void TextOutputter::printHeader() {
  if (result->wasSuccessful())
    out << "\nOK (" << result->runTests() << " tests)\n";
  else {
    out << "\n!!!FAILURES!!!\n";
    out << "Test Results:\n";
    out << "Run: " << result->runTests()
        << "   Failures: " << result->testFailures()
        << "   Errors: " << result->testErrors() << "\n";
  }
}

void TextOutputter::printFailures() {
  auto it = result->failures().begin();
  int failureNumber = 1;
  while (it != result->failures().end()) {
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
