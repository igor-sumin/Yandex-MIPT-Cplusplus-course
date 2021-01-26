#pragma once

#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct Date {
    int year, month, day;
};

struct Time {
    int hours, minutes;
};

struct AirlineTicket {
    string from;
    string to;
    string airline;
    Date departure_date;
    Time departure_time;
    Date arrival_date;
    Time arrival_time;
    int price;
};

// Перегрузили для sort_by.cpp, update_field.cpp
bool operator<(const Date& t1, const Date& t2) {
    return vector<int>{t1.year, t1.month, t1.day} < vector<int>{t2.year, t2.month, t2.day};
}

bool operator<(const Time& t1, const Time& t2) {
    return vector<int>{t1.hours, t1.minutes} < vector<int>{t2.hours, t2.minutes};
}

bool operator==(const Date& t1, const Date& t2) {
    return vector<int>{t1.year, t1.month, t1.day} == vector<int>{t2.year, t2.month, t2.day};
    // return tie(lhs.hours, lhs.minutes) == tie(rhs.hours, rhs.minutes);
}

bool operator==(const Time& t1, const Time& t2) {
    return vector<int>{t1.hours, t1.minutes} == vector<int>{t2.hours, t2.minutes};
}

ostream& operator<<(ostream& stream, const Date& dt) {
    return stream << dt.year << "-" << dt.month << "-" << dt.day << endl;
}

ostream& operator<<(ostream& stream, const Time& tm) {
    return stream << tm.hours << ":" << tm.minutes << endl;
}

// Перегрузили для update_field.cpp
istream& operator>>(istream& stream, Date& dt) {
    stream >> dt.year;
    stream.ignore(1);
    stream >> dt.month;
    stream.ignore(1);
    stream >> dt.day;

    return stream;
}

istream& operator>>(istream& stream, Time& tm) {
    stream >> tm.hours;
    stream.ignore(1);
    stream >> tm.minutes;

    return stream;
}