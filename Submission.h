#ifndef SUBMISSION_H
#define SUBMISSION_H

#include <string>
#include "DateTime.h"
#include "Mark.h"
using namespace std;
class Submission{
    private:
        int sID;
        string output;
        DateTime submissionDate;
        Mark mark;
    
    public:
        Submission();
        Submission(int sID, string output, DateTime& submissionDate, Mark& mark);
        string getOutput();
        int getStudentNumber();
        DateTime getSubmissionTime();
        bool equals(int sID, DateTime& submissionDate);
        void print();
};

#endif