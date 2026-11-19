// Grades a few submissions with Markit's own classes, for the README screenshot.
#include <iostream>
#include "SubmissionServer.h"

int main(){
    SubmissionServer server;

    string items[] = {"insert: ok", "delete: ok", "search: ok", "no leaks"};
    int marks[]    = {3, 3, 2, 2};
    Autograder grader(items, marks, 4);

    DateTime due(2025, 11, 20, 23, 59, 59), lateDue(2025, 11, 21, 11, 59, 59);
    server.addAssignment(2, "Linked lists", due, lateDue, grader);
    server.printAssignments();

    struct { int sID; string output; DateTime when; } subs[] = {
        {1001, "insert: ok | delete: ok | search: ok | no leaks", DateTime(2025, 11, 20, 18, 4, 12)},
        {1002, "insert: ok | delete: ok | search: ok | 2 blocks leaked", DateTime(2025, 11, 20, 23, 41, 7)},
        {1003, "insert: ok | delete: FAILED | search: ok", DateTime(2025, 11, 21, 9, 15, 30)},
        {1004, "insert: ok | delete: ok | search: ok | no leaks", DateTime(2025, 11, 22, 8, 0, 0)},
    };
    for (auto& s : subs){
        bool ok = server.addSubmission(2, s.sID, s.output, s.when);
        cout << "submit " << s.sID << " at " << s.when.getFormattedDateTime()
             << (ok ? "  -> accepted" : "  -> REJECTED (after late due date)") << endl;
    }
    cout << endl << "== Graded submissions ==" << endl;
    server.printSubmissions(2);
    return 0;
}
