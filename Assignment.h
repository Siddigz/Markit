#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <iostream>
#include <string>
#include "DateTime.h"
#include "Autograder.h"
#include "Submission.h"
#include "defs.h"

using namespace std;
class Assignment{
    private:
        int assignNumber;
        string description;
        DateTime dueDate;
        DateTime lateDueDate;
        Autograder grader;
        Submission submissions[MAX_ARRAY];
        int submissionsCount;

    public:
        Assignment();
        Assignment(int assignNumber, string description, DateTime& dueDate, DateTime& lateDueDate, Autograder& grader);
        bool addSubmission(int sID, string output, DateTime& date);
        bool removeSubmission(int sID, DateTime& date);
        int getAssignmentNumber();
        DateTime getDueDate();
        DateTime getLateDueDate();
        void print();
        void printAllSubmissions();
        void printLateSubmissions();
        void printSubmissionsByStudent(int sID);

};


#endif