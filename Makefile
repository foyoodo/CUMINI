
# To compile and run main.

CC=c++
S=src

OBJS = \
	main.o \
	example/triangle/Triangle.o \
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

main : $(OBJS)
	$(CC) -std=c++11 -o main $(OBJS)

$(OBJS): %.o : %.cpp
	$(CC) -std=c++11 -c -o $@ $<

run : main
	@echo "*** main is starting ***" && ./main

all : main

clean :
	rm -f *.o */*.o */*/*.o \
	main

.PHONY : clean
