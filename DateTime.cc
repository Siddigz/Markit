#include "DateTime.h"
#include <iostream>

DateTime::DateTime(){
    DateTime(1900, 1, 1, 0, 0 ,0);
}

DateTime::DateTime(int year, int month, int day, int hour, int minute, int second){
    this->year = year;
    this->month = month;
    this->day = day;
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}


bool DateTime::equals(DateTime& d){
    if(year == d.year && month == d.month && day == d.month && hour == d.hour && minute == d.minute && second == d.second){
        return true;
    }
    return false;
}

bool DateTime::lessThan(DateTime& d){
    if(year < d.year || month < d.month || day < d.month || hour < d.hour || minute < d.minute || second < d.second){
        return true;
    }
    return false;
}

string DateTime::getFormattedDateTime(){
    string formatted;
    



    return formatted;
}

void DateTime::print(){
    
}