
OBJ = Assignment.o Autograder.o DateTime.o main.o Submission.o SubmissionServer.o Tester.o

all: a1

a1: ${OBJ}
	g++ -o a1 ${OBJ}

Assignment.o: defs.h Assignment.h Assignment.cc Autograder.h
	g++ -c Assignment.cc

Autograder.o: defs.h Autograder.h Autograder.cc Submission.h Mark.h
	g++ -c Autograder.cc

DateTime.o: defs.h DateTime.h DateTime.cc
	g++ -c DateTime.cc

Submission.o: defs.h Submission.h Submission.cc DateTime.h Mark.h
	g++ -c Submission.cc

SubmissionServer.o: defs.h SubmissionServer.h SubmissionServer.cc Assignments.h Submissions.h
	g++ -c SubmissionServer.cc

Tester.o: defs.h Tester.h Tester.cc Assignment.h Autograder.h DateTime.h Mark.h Submission.h Submission.h SubmissionServer.h tester.h
	g++ -c Tester.cc

main.o: defs.h Assignment.h Autograder.h DateTime.h Mark.h Submission.h Submission.h SubmissionServer.h
	g++ -c main.cc
	
clean:
	rm -f a1 ${OBJ}