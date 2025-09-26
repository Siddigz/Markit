#observe - Linux is case sensitive. These names should match your filenames exactly

all: test
	
test: test.o Tester.o Autograder.o Mark.o DateTime.o# add object files here and in the command below
	g++ -o test test.o Tester.o Autograder.o Mark.o DateTime.o
		
test.o: test.cc 
	g++ -c test.cc

Tester.o: Tester.h Tester.cc
	g++ -c -g Tester.cc

# add your own classes
Autograder.o: Autograder.h Autograder.cc
	g++ -c -g -Wall Autograder.cc

Mark.o: Mark.h Mark.cc
	g++ -c -g -Wall Mark.cc

DateTime.o: DateTime.h DateTime.cc
	g++ -c -g -Wall DateTime.cc

clean:
	rm -f test *.o
