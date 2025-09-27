#include "SubmissionServer.h"


SubmissionServer::SubmissionServer(){
    assignCount = 0;
};

bool SubmissionServer::addAssignment(int assignNum, string desc, DateTime& due,
    DateTime& lateDue, Autograder& grader){
    if(assignCount == MAX_ARRAY){
        return false;
    }
    Assignment assignment(assignNum, desc, due, lateDue, grader);
    assignments[assignCount] = assignment;
    assignCount++;
    return true;
};

bool SubmissionServer::removeAssignment(int assignNum){
    for(int i = 0; i < assignCount; i++){
        if(assignments[i].getAssignmentNumber() == assignNum){
            for(int n = i; n < assignCount -1; n++){
                assignments[n] = assignments[n+1];
            }
            assignCount--;
            return true;
        }
    }

    return false;
};

bool SubmissionServer::addSubmission(int assignNum, int sID, string output, DateTime& date){
    for(int i = 0; i < assignCount; i++){
        if(assignments[i].getAssignmentNumber() == assignNum){
            return assignments[i].addSubmission(sID,  output,  date);
        }
    }
    return false;
};

bool SubmissionServer::removeSubmission(int assignNum, int sID, DateTime& date){
    for(int i = 0; i < assignCount; i++){
        if(assignments[i].getAssignmentNumber() == assignNum){
            return assignments[i].removeSubmission( sID,  date);
        }
    }
    return false;
};

void SubmissionServer::printAssignments(){
    for(int i = 0; i < assignCount; i++){
        assignments[i].print();
    }
};

void SubmissionServer::printSubmissions(int assignNum){
    for(int i = 0; i < assignCount; i++){
        if(assignments[i].getAssignmentNumber() == assignNum){
            assignments[i].printAllSubmissions();
        }
    }
};

void SubmissionServer::printSubmissionsByStudent(int sID){
    for(int i = 0; i < assignCount; i++){
        assignments[i].printSubmissionsByStudent(sID);
    }
};
