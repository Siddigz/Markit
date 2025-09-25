#ifndef MARK_H
#define MARK_H

#include <iostream>
using namespace std;

class Mark{
    private:
        int mark;
        int outof;

    public:
        Mark(){
            mark = 0;
            outof = 0;
        }

        Mark(int mark, int outof){
            this->mark = mark;
            this->outof = outof;
        }

        void print(){
            cout << "Mark: " << mark << " out of " << outof << endl;
        }

        void changeMark(int newMark){
            this->mark = newMark;
        }

        void changeOutOf(int newOutOf){
            this->outof = newOutOf;
        }

};


#endif