#ifndef SUBMISSIONSERVER_H
#define SUBMISSIONSERVER_H

#include "Assignment.h"
using namespace std;

class SubmissionServer{
    private: 
        Assignment assignments[MAX_ARRAY];
        int assignCount;

    public:
        SubmissionServer();
        bool addAssignment(int assignNum, string desc, DateTime& due, DateTime& lateDue, Autograder& grader);
        bool removeAssignment(int assignNum);
        bool addSubmission(int assignNum, int sID, string output, DateTime& date);
        bool removeSubmission(int assignNum, int sID, DateTime& date);
        void printAssignments();
        void printSubmissions(int assignNum);
        void printSubmissionsByStudent(int sID);

        
};

#endif