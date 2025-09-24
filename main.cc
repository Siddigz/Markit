#include <iostream>
#include <random>
#include <sstream>
#include "SubmissionServer.h"
#include "Tester.h"
#include "Autograder.h"


using namespace std;

// unit tests for Submissions and Assignments
int testSubmissions();
int testAssignments();
int testAssignmentWithSubmissions();

// Integration tests for SubmissionServer
int serverTestAssignments();
int serverTestSubmissions();

int main(){
    int choice = -1;
    while(choice != 0 && cin.good()){
        std::cout<<endl;
        std::cout<<" 0. Exit"<<endl;
        std::cout<<" Unit tests for Submissions and Assignments:"<<endl;
        
        std::cout<<" 1. [4 marks] Test Submissions"<<endl;

        std::cout<<" 2. [3 marks] Test Assignments"<<endl;
        std::cout<<" 3. [8 marks] Test Assignments with Submissions"<<endl;
        std::cout<<endl<<" SubmissionServer tests:"<<endl;
        std::cout<<" 4. [5 marks] Test add, remove, and print Assignments in SubmissionServer"<<endl;
        std::cout<<" 5. [10 marks] Test add, remove, and print Submissions in SubmissionServer"<<endl; 


        std::cout<<" 6. [30 marks] Test all and get mark"<<endl<<endl;
        cin >> choice;
        std::cout<<endl;

        // clear the buffer since buffers are a pain in the butt
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (choice)
        {
            case 1: testSubmissions(); break;  
            case 2: testAssignments(); break;  
            case 3: testAssignmentWithSubmissions(); break;
            case 4: serverTestAssignments(); break;
            case 5: serverTestSubmissions(); break;
            case 6: 
                int score = 0;
                score += testSubmissions();
                score += testAssignments();
                score += testAssignmentWithSubmissions();
                score += serverTestAssignments();
                score += serverTestSubmissions();
                std::cout << "Your score is "<<score<<" out of 30" << endl << endl;
                break;
        }
    }
    std::cout<<"Bye!"<<endl;
    return 0;  
}


Tester tester;


int testSubmissions(){
    Submission submissions[5];		

    Tester tester;

    int student_numbers[5] = {1001, 1002, 1003, 1004, 1005};
    string sn_strings[5] = {"1001", "1002", "1003", "1004", "1005"};
    string output[5] = {"AAA", "BBB", "CCC", "DDD", "EEE"};
    int num_people[5] = {1, 2, 3, 4, 5};
    DateTime* submissionDate[5] = {new DateTime(2024, 1, 1, 1, 1, 1), new DateTime(2024, 2, 2, 2, 2, 2), new DateTime(2024, 3, 3, 3, 3, 3), new DateTime(2024, 4, 4, 4, 4, 4), new DateTime(2024, 5, 5, 5, 5, 5)};

    string submissionDateStrings[5];

    Mark* marks[5] = {new Mark{10, 10}, new Mark{9, 10}, new Mark{8, 10}, new Mark{7, 10}, new Mark{6, 10}};

    string markStrings[] = {"10/10", "9/10", "8/10", "7/10", "6/10"};

    // Convert the dates to strings and make submissions
    cout<<"Making date strings"<<endl;
    for (int i = 0; i < 5; i++){
        submissionDateStrings[i] = submissionDate[i]->getFormattedDateTime();
        cout<<"Making submission "<<i<<endl;
        submissions[i] = Submission(student_numbers[i], output[i], *submissionDate[i], *marks[i]);
        // The student should be making copies of these objects.
        // If they are not making copies, this should crash when they are printed.
        delete submissionDate[i];
        delete marks[i];
    }

    cout<<"Testing Print Submission class"<<endl<<endl;
    
    tester.initCapture();
    for (int i = 0; i < 5; i++){
        submissions[i].print();
    }
    tester.endCapture();

    int score = 0;
    int error = 0;
    tester.find({0,1,2,3,4}, sn_strings, error);
    if(error > 0){
        cout<<"Error: Some student numbers not found"<<endl;
    }else{
        cout<<"All student numbers found, 1 point earned"<<endl;
        ++score;
    }

    tester.find({0,1,2,3,4}, output, error);
    if(error > 0){
        cout<<"Error: Some output not found"<<endl;
    }else{
        cout<<"All output found, 1 point earned"<<endl;
        ++score;
    }

    tester.find({0,1,2,3,4}, submissionDateStrings, error);
    if(error > 0){
        cout<<"Error: Some submissionDateStrings not found"<<endl;
    }else{
        cout<<"All submissionDateStrings found, 1 point earned"<<endl;
        ++score;
    }

    tester.find({0,1,2,3,4}, markStrings, error);
    if(error > 0){
        cout<<"Error: Some marks not found"<<endl;
    }else{
        cout<<"All marks found, 1 point earned"<<endl;
        ++score;
    }

    

    cout<<"Points earned: "<<score<<"/4"<<endl<<endl;
    return score;
}

int testAssignments(){
    Assignment assignments[5];

    int assign_numbers[5] = {1, 2, 3, 4, 5};
    string descriptions[5] = {"Lakeside", "Mountain View", "Forest", "Desert", "Beach"};
    DateTime* dueDates[5] = {new DateTime(2024, 5, 1, 12, 0, 0), new DateTime(2024, 6, 1, 12, 0, 0), new DateTime(2024, 7, 1, 12, 0, 0), new DateTime(2024, 8, 1, 12, 0, 0), new DateTime(2024, 9, 1, 12, 0, 0)};
    DateTime* lateDueDates[5] = {new DateTime(2024, 5, 15, 12, 0, 0), new DateTime(2024, 6, 15, 12, 0, 0), new DateTime(2024, 7, 15, 12, 0, 0), new DateTime(2024, 8, 15, 12, 0, 0), new DateTime(2024, 9, 15, 12, 0, 0)};

    string dueDateStrings[5];
    string lateDueDateStrings[5];

    cout<<"Making assignments"<<endl;

    Autograder* autograder = new Autograder();
    for (int i = 0; i < 5; i++){
        dueDateStrings[i] = dueDates[i]->getFormattedDateTime();
        lateDueDateStrings[i] = lateDueDates[i]->getFormattedDateTime();
        assignments[i] = Assignment(assign_numbers[i], descriptions[i], *dueDates[i], *lateDueDates[i], *autograder);
        // The student should be making copies of these objects.
        // If they are not making copies, this should crash when they are printed.
        delete dueDates[i];
        delete lateDueDates[i];
    }

    delete autograder;  
    cout<<"Testing Print Assignment class"<<endl<<endl;

    tester.initCapture();
    for (int i = 0; i < 5; i++){
        assignments[i].print();
    }
    tester.endCapture();

    int score = 0;
    int error = 0;
    tester.find({0,1,2,3,4}, descriptions, error);
    if(error > 0){
        cout<<"Error: Some descriptions not found"<<endl;
    }else{
        cout<<"All descriptions found, 1 point earned"<<endl;
        ++score;
    }

    tester.find({0,1,2,3,4}, dueDateStrings, error);
    if(error > 0){
        cout<<"Error: Some dueDates not found"<<endl;
    }else{
        cout<<"All dueDates found, 1 point earned"<<endl;
        ++score;
    }


    tester.find({0,1,2,3,4}, lateDueDateStrings, error);
    if(error > 0){
        cout<<"Error: Some late due dates not found"<<endl;
    }else{
        cout<<"All late due dates found, 1 point earned"<<endl;
        ++score;
    }

    cout<<"Points earned: "<<score<<"/3"<<endl<<endl;

    return score;
}

int testAssignmentWithSubmissions(){
    cout<<"test Assignment add, remove, and print Submissions"<<endl;
    string outputs[] = {"A", "B", "C"};
    int marks[] = {1, 2, 4};

    Autograder grader(outputs, marks, 3);

    DateTime dueDate(2025, 9, 21, 23, 59, 59);
    DateTime lateDueDate(2025, 9, 22, 23, 59, 58);
    Assignment assignment(1, "Assignment 1", dueDate, lateDueDate, grader);

    int student_numbers[5] = {101, 101, 103, 104, 105};
    string sn_strings[5] = {"101", "101", "103", "104", "105"};
    string output[5] = {"AAA", "BBB", "ACC", "DDD", "ABC"};
    string grades[5] = {"1/7", "2/7", "5/7", "0/7", "7/7"};
    // on time, just on time, late (not accepted), late (but accepted), late (but accepted)
    DateTime submissionDate[5] = {DateTime(2025, 9, 20, 11, 45, 33), DateTime(2025, 9, 21, 23, 59, 59), DateTime(2025, 9, 22, 23, 59, 59), DateTime(2025, 9, 22, 2, 59, 59), DateTime(2025, 9, 22, 23, 1, 59)};

    cout<<"Adding submissions"<<endl;
    for (int i = 0; i < 5; i++){
        cout<<"Adding submission "<<i<<endl;
        assignment.addSubmission(student_numbers[i], output[i], submissionDate[i]);
    }

    cout<<"Testing Print Assignment class"<<endl<<endl;

    tester.initCapture();
    assignment.printAllSubmissions();
    tester.endCapture();

    int score = 0;
    int error = 0;

    tester.find({0,3,4}, sn_strings, error);
    if(error > 0){
        cout<<"Error: Some student numbers not found"<<endl;
        // return score;
    }else{
        cout<<"All student numbers found, 1 point earned"<<endl;
        ++score;
    }

    tester.confirmAbsent({2}, sn_strings, error);
    if(error > 0){
        cout<<"Error: Student number 103 found but should not be"<<endl;
        // return score;
    }else{
        cout<<"Student number 103 not found, 1 point earned"<<endl;
        ++score;
    }

    cout<<"Printing submissions by student 101: ";
    tester.initCapture();
    assignment.printSubmissionsByStudent(101);
    tester.endCapture();

    tester.find({0}, sn_strings, error);
    if(error > 0){
        cout<<"Error: "<<sn_strings[0]<<" not found"<<endl;
    }else{
        cout<<sn_strings[0]<<" found, 1 point earned"<<endl;
        ++score;
    }

    tester.confirmAbsent({3,4}, sn_strings, error);
    if(error > 0){
        cout<<"Error: Wrong student numbers printed"<<endl;
    }else{
        cout<<"No wrong student numbers printed, 1 point earned"<<endl;
        ++score;
    }

    cout<<"Printing late submissions: ";
    tester.initCapture();
    assignment.printLateSubmissions();
    tester.endCapture();

    tester.find({3, 4}, sn_strings, error);
    if(error > 0){
        cout<<"Error: "<<sn_strings[3]<<" or "<<sn_strings[4]<<" not found"<<endl;
    }else{
        cout<<"All students found, 1 point earned"<<endl;
        ++score;
    }

    tester.confirmAbsent({0}, sn_strings, error);
    if(error > 0){
        cout<<"Error: Wrong student numbers printed"<<endl;
    }else{
        cout<<"No wrong student numbers printed, 1 point earned"<<endl;
        ++score;
    }

    assignment.removeSubmission(student_numbers[3], submissionDate[3]);

    cout<<"Printing submissions after removing "<<sn_strings[3]<<endl;
    tester.initCapture();
    assignment.printAllSubmissions();
    tester.endCapture();

    tester.find({0,4}, sn_strings, error);
    if(error > 0){
        cout<<"Error: Some names not found"<<endl;
    }else{
        cout<<"All names found, 1 point earned"<<endl;
        ++score;
    }

    tester.confirmAbsent({3}, sn_strings, error);
    if(error > 0){
        cout<<"Error: Student number "<<sn_strings[3]<<" found but was removed"<<endl;
    }else{
        cout<<"Student number "<<sn_strings[3]<<" not found, 1 point earned"<<endl;
        ++score;
    }



    cout<<"Points earned: "<<score<<"/8"<<endl<<endl;
    return score;

}


int serverTestAssignments(){
    SubmissionServer submissionserver;

    int assign_numbers[5] = {1, 2, 3, 4, 5};
    string descriptions[5] = {"Lakeside", "Mountain View", "Forest", "Desert", "Beach"};
    DateTime* dueDates[5] = {new DateTime(2024, 5, 1, 12, 0, 0), new DateTime(2024, 6, 1, 12, 0, 0), new DateTime(2024, 7, 1, 12, 0, 0), new DateTime(2024, 8, 1, 12, 0, 0), new DateTime(2024, 9, 1, 12, 0, 0)};
    DateTime* lateDueDates[5] = {new DateTime(2024, 5, 15, 12, 0, 0), new DateTime(2024, 6, 15, 12, 0, 0), new DateTime(2024, 7, 15, 12, 0, 0), new DateTime(2024, 8, 15, 12, 0, 0), new DateTime(2024, 9, 15, 12, 0, 0)};

    string dueDateStrings[5];
    string lateDueDateStrings[5];

    cout<<"Making assignments"<<endl;

    Autograder* autograder = new Autograder();
    for (int i = 0; i < 5; i++){
        dueDateStrings[i] = dueDates[i]->getFormattedDateTime();
        lateDueDateStrings[i] = lateDueDates[i]->getFormattedDateTime();
        submissionserver.addAssignment(assign_numbers[i], descriptions[i], *dueDates[i], *lateDueDates[i], *autograder);
        // The student should be making copies of these objects.
        // If they are not making copies, this should crash when they are printed.
        delete dueDates[i];
        delete lateDueDates[i];
    }

    delete autograder;  
    cout<<"Testing Print Assignment class"<<endl<<endl;

    tester.initCapture();
    
    submissionserver.printAssignments();

    tester.endCapture();

    int score = 0;
    int error = 0;
    tester.find({0,1,2,3,4}, descriptions, error);
    if(error > 0){
        cout<<"Error: Some descriptions not found"<<endl;
    }else{
        cout<<"All descriptions found, 1 point earned"<<endl;
        ++score;
    }

    tester.find({0,1,2,3,4}, dueDateStrings, error);
    if(error > 0){
        cout<<"Error: Some dueDates not found"<<endl;
    }else{
        cout<<"All dueDates found, 1 point earned"<<endl;
        ++score;
    }


    tester.find({0,1,2,3,4}, lateDueDateStrings, error);
    if(error > 0){
        cout<<"Error: Some late due dates not found"<<endl;
    }else{
        cout<<"All late due dates found, 1 point earned"<<endl;
        ++score;
    }
    int removedAssignment = 2;
    cout<<endl<<endl<<"Removing assignment "<<assign_numbers[removedAssignment]<<endl;

    submissionserver.removeAssignment(assign_numbers[removedAssignment]);

    tester.initCapture();
    submissionserver.printAssignments();
    tester.endCapture();

    tester.find({0,1,3,4}, descriptions, error);
    if(error > 0){
        cout<<"Error: Some descriptions not found"<<endl;
    }else{
        cout<<"All descriptions found, 1 point earned"<<endl;
        ++score;
    }

    tester.confirmAbsent({2}, descriptions, error);
    if(error > 0){
        cout<<"Error: description "<<descriptions[removedAssignment]<<" found "<<endl;
    }else{
        cout<<"Removed description "<<descriptions[removedAssignment]<<" not found, 1 point earned"<<endl;
        ++score;
    }

    cout<<"Points earned: "<<score<<"/5"<<endl<<endl;

    return score;
}

int serverTestSubmissions(){
    SubmissionServer submissionserver;
    // SubmissionServer submissionserver2;
    cout<<endl<<"submissionserver testPrintSubmissions"<<endl;

    cout<<"test Assignment add, remove, and print Submissions"<<endl;
    string outputs[] = {"A", "B", "C"};
    int marks[] = {1, 2, 4};

    Autograder grader1(outputs, marks, 3);
    Autograder grader2(outputs, marks, 2);
    Autograder grader3(outputs, marks, 1);

    DateTime     dueDate1(2025, 9, 21, 23, 59, 59);
    DateTime lateDueDate1(2025, 9, 22, 23, 59, 58);

    DateTime     dueDate2(2025, 10, 21, 23, 59, 59);
    DateTime lateDueDate2(2025, 10, 23, 23, 59, 58);

    DateTime     dueDate3(2025, 11, 21, 23, 59, 59);
    DateTime lateDueDate3(2025, 11, 22, 12, 59, 58);

    submissionserver.addAssignment(1, "Assignment 1", dueDate1, lateDueDate1, grader1);
    submissionserver.addAssignment(2, "Assignment 2", dueDate2, lateDueDate2, grader2);
    submissionserver.addAssignment(3, "Assignment 3", dueDate3, lateDueDate3, grader3);

    /*********************************************Pick up here */

    int student_numbers[5] = {101, 101, 103, 104, 105};
    string sn_strings[5] = {"101", "101", "103", "104", "105"};
    string output[5] = {"Abracadaba", "Bob the builder", "AC-DC", "Air Conditioning", "Alpha Beta Charlie"};
    string grades[5] = {"1/7", "2/7", "5/7", "1/3", "1/1"};
    int assignment_numbers[5] = {1, 1, 1, 2, 3};
    // a1, a1 (late), a1, a2, a3
    DateTime submissionDate[5] = {DateTime(2025, 9, 21, 23, 59, 59), DateTime(2026, 9, 21, 23, 59, 59), DateTime(2025, 9, 21, 23, 59, 59), DateTime(2025, 10, 21, 23, 59, 59), DateTime(25, 11, 21, 23, 59, 5)};

    cout<<"Adding submissions"<<endl;
    for (int i = 0; i < 5; i++){
        cout<<"Adding submission "<<i<<endl;
        submissionserver.addSubmission(assignment_numbers[i], student_numbers[i], output[i], submissionDate[i]);
    }

    cout<<"Testing Print submissions in assignment"<<endl<<endl;

    
    tester.initCapture();
    submissionserver.printSubmissions(1);
    tester.endCapture();

    int score = 0;
    int error = 0;

    tester.find({0,2}, output, error);
    if(error > 0){
        cout<<"Error: Some outputs not found"<<endl;
        // return score;
    }else{
        cout<<"All outputs found, 1 point earned"<<endl;
        ++score;
    }

    tester.confirmAbsent({1,3,4}, output, error);
    if(error > 0){
        cout<<"Error: some outputs found but should not be"<<endl;
        // return score;
    }else{
        cout<<"No bad outputs found, 1 mark"<<endl;
        ++score;
    }

    tester.initCapture();
    submissionserver.printSubmissions(2);
    tester.endCapture();

    
    error = 0;

    tester.find({3}, output, error);
    if(error > 0){
        cout<<"Error: Some outputs not found"<<endl;
        // return score;
    }else{
        cout<<"All outputs found, 1 point earned"<<endl;
        ++score;
    }

    tester.confirmAbsent({0,2,4}, output, error);
    if(error > 0){
        cout<<"Error: some outputs found but should not be"<<endl;
        // return score;
    }else{
        cout<<"No bad outputs found, 1 mark"<<endl;
        ++score;
    }

    tester.initCapture();
    submissionserver.printSubmissions(3);
    tester.endCapture();

    
    error = 0;

    tester.find({4}, output, error);
    if(error > 0){
        cout<<"Error: Some outputs not found"<<endl;
        // return score;
    }else{
        cout<<"All outputs found, 1 point earned"<<endl;
        ++score;
    }

    tester.confirmAbsent({0,2,3}, output, error);
    if(error > 0){
        cout<<"Error: some outputs found but should not be"<<endl;
        // return score;
    }else{
        cout<<"No bad outputs found, 1 mark"<<endl;
        ++score;
    }

    cout<<endl<<"Testing remove submission"<<endl<<endl;

    submissionserver.removeSubmission(1, student_numbers[0], submissionDate[0]);
    
    tester.initCapture();
    submissionserver.printSubmissions(1);
    tester.endCapture();

    
    error = 0;

    tester.find({2}, output, error);
    if(error > 0){
        cout<<"Error: Some outputs not found"<<endl;
        // return score;
    }else{
        cout<<"All outputs found, 1 point earned"<<endl;
        ++score;
    }

    tester.confirmAbsent({0,1,3,4}, output, error);
    if(error > 0){
        cout<<"Error: some outputs found but should not be"<<endl;
        // return score;
    }else{
        cout<<"No bad outputs found, 1 mark"<<endl;
        ++score;
    }

    cout<<"Printing submissions by student 104: ";
    tester.initCapture();
    submissionserver.printSubmissionsByStudent(104);
    tester.endCapture();

    tester.find({3}, output, error);
    if(error > 0){
        cout<<"Error: "<<output[3]<<" not found"<<endl;
    }else{
        cout<<output[3]<<" found, 1 point earned"<<endl;
        ++score;
    }

    tester.confirmAbsent({2,4}, output, error);
    if(error > 0){
        cout<<"Error: Wrong output printed"<<endl;
    }else{
        cout<<"No wrong output printed, 1 point earned"<<endl;
        ++score;
    }

    cout<<"Points earned: "<<score<<"/10"<<endl<<endl;
    return score;

}

