#include "Mark.h"
#include <iostream>


Mark::Mark(){
    mark = 0;
    outof = 0;
}

Mark::Mark(int mark, int outof){
    this->mark = mark;
    this->outof = outof;
}

void Mark::print(){
    cout << "(" << mark << "/" << outof << ")" << endl;
}

void Mark::changeMark(int newMark){
    this->mark = newMark;
}

void Mark::changeOutOf(int newOutOf){
    this->outof = newOutOf;
}