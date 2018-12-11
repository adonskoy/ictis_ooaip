#include <fstream>
#include <vector>

struct Time {
    short int _h;
    short int _m;
    short int _s;
};

struct Date {
    short int _d;
    short int _m;
    short int _y;
};

struct DateTime {
    Date _date;
    Time _time;

};

bool operator<=(const Date &D1, const Date &D2);

bool operator==(const Date &D1, const Date &D2);

bool operator>(const Date &D1, const Date &D2);

bool operator>=(const Date &D1, const Date &D2);

bool operator<(const Date &D1, const Date &D2);

bool operator!=(const Date &D1, const Date &D2);


bool operator<=(const Time &T1, const Time &T2);

bool operator==(const Time &T1, const Time &T2);

bool operator>(const Time &T1, const Time &T2);

bool operator>=(const Time &T1, const Time &T2);

bool operator<(const Time &T1, const Time &T2);

bool operator!=(const Time &T1, const Time &T2);


bool operator==(const DateTime &DT1, const DateTime &DT2);

bool operator<=(const DateTime &DT1, const DateTime &DT2);

bool operator>(const DateTime &DT1, const DateTime &DT2);

bool operator>=(const DateTime &DT1, const DateTime &DT2);

bool operator<(const DateTime &DT1, const DateTime &DT2);

bool operator!=(const DateTime &DT1, const DateTime &DT2);


std::ostream &operator<<(std::ostream &os, DateTime &dt);

std::istream &operator>>(std::istream &is, DateTime &dt);
