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
    if(year == d.year && month == d.month && day == d.day && hour == d.hour && minute == d.minute && second == d.second){
        return true;
    }
    return false;
}

bool DateTime::lessThan(DateTime& d){
    if (year != d.year) return year < d.year;
    if (month != d.month) return month < d.month;
    if (day != d.day) return day < d.day;
    if (hour != d.hour) return hour < d.hour;
    if (minute != d.minute) return minute < d.minute;
    if (second != d.second) return second < d.second;
    return false;
}

string DateTime::getFormattedDateTime(){
    string formatted = "(" + to_string(year) + "/" +  to_string(month) + "/" +  to_string(day) + " " +  to_string(hour) + ":" +  to_string(minute) + ":" +  to_string(second) + ")";
    // string formatted = std::format("({year}/{month}/{day} {hour}:{minute}:{second})");

    return formatted;
}

// void DateTime::print(){
    
// }