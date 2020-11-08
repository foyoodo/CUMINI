#ifndef TESTCALLER_H
#define TESTCALLER_H

#include "TestCase.h"

#include <functional>
#include <string>

template <class Fixture> class TestCaller : public TestCase {

  typedef void (Fixture::*TestMethod)();

public:
  // Create a new fixture as own fixture.
  TestCaller(std::string name, TestMethod testMethod)
      : TestCase(name), ownFixture(true), fixture(new Fixture()),
        testFunction(std::bind(testMethod, fixture)) {}

  // Accept a pointer and use the existing fixture as own fixture.
  TestCaller(std::string name, TestMethod testMethod, Fixture *fixture)
      : TestCase(name), ownFixture(true), fixture(fixture),
        testFunction(std::bind(testMethod, fixture)) {}

  // The specified fixture is an existing one, not own by the TestCaller
  TestCaller(std::string name, TestMethod testMethod, Fixture &fixture)
      : TestCase(name), ownFixture(false), fixture(&fixture),
        testFunction(std::bind(testMethod, &fixture)) {}

  TestCaller(std::string name, std::function<void()> testFunction)
      : TestCase(name), ownFixture(true), fixture(new Fixture()),
        testFunction(testFunction) {}

  TestCaller(std::string name, std::function<void()> testFunction,
             Fixture *fixture)
      : TestCase(name), ownFixture(true), fixture(fixture),
        testFunction(testFunction) {}

  TestCaller(std::string name, std::function<void()> testFunction,
             Fixture &fixture)
      : TestCase(name), ownFixture(true), fixture(&fixture),
        testFunction(testFunction) {}

  ~TestCaller() {
    if (ownFixture)
      delete fixture;
  }

  void setUp() { fixture->setUp(); }

  void tearDown() { fixture->tearDown(); }

  void runTest() { testFunction(); }

private:
  bool ownFixture;
  Fixture *fixture;
  std::function<void()> testFunction;
};

#endif
