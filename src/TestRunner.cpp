#include "../include/TestRunner.h"
#include "../include/TestSuite.h"

namespace CUMINI {

TestRunner::TestRunner() : suite(new TestSuite()) {}

TestRunner::~TestRunner() { delete suite; }

void TestRunner::addTest(Test *test) { suite->addTest(test); }

void TestRunner::run(TestResult *result) { suite->run(result); }

int TestRunner::getChildTestCount() const { return suite->getChildTestCount(); }

} // namespace CUMINI
