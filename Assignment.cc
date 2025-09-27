#include "Assignment.h"

// using namespace std;

Assignment::Assignment(){
    submissionsCount = 0;
}

Assignment::Assignment(int assignNumber, string description, DateTime& dueDate, 
DateTime& lateDueDate, Autograder& grader){
    this->assignNumber = assignNumber;
    this->description = description;
    this->dueDate = dueDate;
    this->lateDueDate = lateDueDate;
    this->grader = grader;
    this->submissionsCount = 0;
}

bool Assignment::addSubmission(int sID, string output, DateTime& date){
    if(submissionsCount == MAX_ARRAY) return false;
    if(date.lessThan(lateDueDate)){
        Mark mark;
        grader.mark(output, mark);
        Submission file(sID, output, date, mark);
        submissions[submissionsCount] = file;
        submissionsCount++;
        return true;
    }
    return false;
}

bool Assignment::removeSubmission(int sID, DateTime& date){
    for(int i = 0; i < submissionsCount; i++){
        if(submissions[i].getStudentNumber() == sID && submissions[i].getSubmissionTime().equals(date)){
            for(int n = i; n < submissionsCount; n++){
                submissions[n] = submissions[n+1];
            }

            submissionsCount--;
            return true;
        }
    }
    return false;
}

int Assignment::getAssignmentNumber(){
    return assignNumber;
}

DateTime Assignment::getDueDate(){
    return dueDate;
}

DateTime Assignment::getLateDueDate(){
    return lateDueDate;
}

void Assignment::print(){
// Assignment Number: 3
// Description: Assignment 3
// Due Date: December 21, 2025, 23:59:59
// Late Due Date: December 22, 2025, 12:59:58
// Number of Submissions: 40
    cout << "Assignment Number: " << assignNumber << endl;
    cout << "Description:" << description << endl;
    cout << "Due Date:  " << dueDate.getFormattedDateTime() << endl;
    cout << "Late Due Date: " << lateDueDate.getFormattedDateTime() << endl;
    cout << "Number of Submissions: " << submissionsCount << endl;
}

void Assignment::printAllSubmissions(){
    for(int i = 0; i < submissionsCount; i++){
        submissions[i].print();
    }
}

void Assignment::printLateSubmissions(){
    for(int i = 0; i < submissionsCount; i++){
        if(!submissions[i].getSubmissionTime().lessThan(dueDate)){
            submissions[i].print();
        }
    }
}

void Assignment::printSubmissionByStudent(int sID){
    for(int i = 0; i < submissionsCount; i++){
        if(submissions[i].getStudentNumber() == sID){
            submissions[i].print();
        }
        break;
    }
}




