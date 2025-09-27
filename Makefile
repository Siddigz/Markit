OPT = -g -Wall -Wextra
OBJ = Tester.o Assignment.o Autograder.o Mark.o DateTime.o Submission.o SubmissionServer.o main.o
all: a1

a1: ${OBJ}
	g++ -o a1 ${OBJ}

Tester.o: Tester.h Tester.cc
	g++ -c Tester.cc

Autograder.o: Autograder.h Autograder.cc
	g++ -c ${OPT} Autograder.cc

Mark.o: Mark.h Mark.cc
	g++ -c ${OPT} Mark.cc

DateTime.o: DateTime.h DateTime.cc
	g++ -c ${OPT} DateTime.cc

Submission.o: Submission.h Submission.cc
	g++ -c ${OPT} Submission.cc

Assignment.o: Assignment.h Assignment.cc
	g++ -c ${OPT} Assignment.cc

SubmissionServer.o: SubmissionServer.h SubmissionServer.cc
	g++ -c ${OPT} SubmissionServer.cc

main.o: main.cc
	g++ -c ${OPT} main.cc 

clean:
	rm -f a1 ${OBJ}
