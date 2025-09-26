#ifndef MARK_H
#define MARK_H
#include <iostream>

using namespace std;

class Mark{
    private:
        int mark;
        int outof;

    public:
        Mark();
        Mark(int mark, int outof);
        void print();
        void changeMark(int newMark);
        void changeOutOf(int newOutOf);

};


#endif