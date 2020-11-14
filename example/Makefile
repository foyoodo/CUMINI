
# To compile and run Tests.

CC=c++
S=../src

COBJ = \
	calculator/CalculatorTest.o

TOBJ = \
	triangle/TriangleTest.o \
	triangle/Triangle.o

OBJS = \
	$S/Asserter.o \
	$S/Exception.o \
	$S/Test.o \
	$S/TestCase.o \
	$S/TestComposite.o \
	$S/TestFailure.o \
	$S/TestLeaf.o \
	$S/TestResult.o \
	$S/TestResultCollector.o \
	$S/TestRunner.o \
	$S/TestSuite.o \
	$S/TextOutputter.o

CalculatorTest : $(OBJS) $(COBJ)
	$(CC) -std=c++11 -o CalculatorTest $(OBJS) $(COBJ)

TriangleTest : $(OBJS) $(TOBJ)
	$(CC) -std=c++11 -o TriangleTest $(OBJS) $(TOBJ)

$(OBJS) $(TOBJ) $(COBJ) : %.o : %.cpp
	$(CC) -std=c++11 -c -o $@ $<

calculator : CalculatorTest
	@echo "\n*** CalculatorTest is starting ***\n" && ./CalculatorTest

triangle : TriangleTest
	@echo "\n*** TriangleTest is starting ***\n" && ./TriangleTest

clean :
	rm -f */*.o \
	CalculatorTest TriangleTest

clean_all :
	rm -f */*.o ../*/*.o \
	CalculatorTest TriangleTest

.PHONY : calculator triangle clean clean_all
