#include "Submission.h"



Submission::Submission(){
    sID = 0;
};

Submission::Submission(int sID, string output, DateTime& submissionDate, Mark& mark){
        this->sID = sID;
        this->output = output;
        this->submissionDate = submissionDate;
        this->mark = mark;
};

string Submission::getOutput(){
    return output;
};

int Submission::getStudentNumber(){
    return sID;
};

DateTime Submission::getSubmissionTime(){
    return submissionDate;
};

bool Submission::equals(int sID, DateTime& submissionDate){
    if(this->sID == sID && this->submissionDate.equals(submissionDate)){
        return true;
    }
    return false;
};

void Submission::print(){
    cout << "\nSubmission by " << sID << " on " << submissionDate.getFormattedDateTime() << endl;
    mark.print();
    cout << output << endl << endl;
};
