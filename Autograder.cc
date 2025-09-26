#include "Autograder.h"

Autograder::Autograder(){
    itemsCount = 0;
}

Autograder::Autograder(string markingItems[], int marks[], int itemsCount){
    this->itemsCount = itemsCount;
    for(int i = 0; i < itemsCount; i++){
        this->markingItems[i] = markingItems[i];
        this->marks[i] = marks[i];
    }
}

void Autograder::mark(string output, Mark& mark){
    int total = 0;
    for(int i = 0; i < itemsCount; i++){
        total += marks[i];
    }
    mark.changeOutOf(total);

    int grade = 0;
    for(int i = 0; i < itemsCount; i++){
        if( output.find(markingItems[i]) != std::string::npos ){
            grade += marks[i];
        }
    }

    mark.changeMark(grade);
}