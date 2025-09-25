#ifndef DATETIME_H
#define DATETIME_H
#include <string.h>
#include <string>

using namespace std;

class DateTime{
    private:
        int year, month, day, hour, minute, second;

    public:
        DateTime();
        DateTime(int year, int month, int day, int hour, int minute, int second);
        bool equals(DateTime& d);
        bool lessThan(DateTime& d);
        string getFormattedDateTime();
        // void print();

};


enum Month{
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

#endif