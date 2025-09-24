#ifndef AUTOGRADER_H
#define AUTOGRADER_H

using namespace std;
#include <defs.h>
#include <string.h>
#include <Mark.h>

class Autograder{
    private:
        string markingItems[MAX_ARRAY];
        int marks[MAX_ARRAY];
        int itemsCount;

    public:
        Autograder();
        Autograder(string markingItems[], int marks[], int itemsCount);
        void mark(string output, Mark& mark);

};




#endif