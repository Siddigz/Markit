#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <string>
#include "DateTime.h"
#include "Autograder.h"
#include "Submission.h"
#include "defs.h"

using namespace std;
class Assignment{
    private:
        int assign_number;
        string description;
        DateTime dueDate;
        DateTime lateDueDate;
        Autograder grader;
        Submission submissions[MAX_ARRAY];
        int submissionsCount;

    public:
        Assignment();
        Assignment(int assign_number, string description, DateTime& dueDate, DateTime& lateDueDate, Autograder& grader, Submission& submissions, int submissionsCount);
        bool addSubmission(int sID, string output, DateTime& date, Submission& submission);
        bool removeSubmission(int sID, DateTime& date, Submission& submission);
        int getAssignmentNumber();
        DateTime getDueDate();
        DateTime getLateDueDate();
        void print();
        void printAllSubmissions();
        void printLateSubmissions();
        void printSubmissionByStudent(int sID);

};


#endif