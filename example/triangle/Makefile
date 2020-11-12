
# To compile and run TriangleTest.

CC=c++
S=../../src

OBJS = \
	TriangleTest.o \
	Triangle.o \
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

TriangleTest : $(OBJS)
	$(CC) -std=c++11 -o TriangleTest $(OBJS)

$(OBJS): %.o : %.cpp
	$(CC) -std=c++11 -c -o $@ $<

run : TriangleTest
	@echo "\n*** TriangleTest is starting ***\n" && ./TriangleTest

clean :
	rm -f *.o */*.o ../../*/*.o \
	TriangleTest

.PHONY : clean
