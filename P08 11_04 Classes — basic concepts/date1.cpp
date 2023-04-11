#include "Date1.h"
#include <string>
#include <iostream>
using namespace std;

Date::Date() : Date(1, 1, 1) {}

Date::Date(int year, int month, int day) {
    Date::year = year;
    Date::month = month;
    Date::day = day;
}

int Date::get_year() const {
    return year;
}

int Date::get_month() const {
    return month;
}

int Date::get_day() const {
    return day;
}

bool is_before(const Date& date1, const Date& date2) {
    int date1_year = date1.get_year();
    int date2_year = date2.get_year();
    if (date1_year < date2_year) {
        return true;
    }
    if (date1_year == date2_year) {
        int date2_month = date2.get_month();
        int date1_month = date1.get_month();
        if (date1_month < date2_month) {
            return true;
        }
        if (date1_month == date2_month) {
            int date1_day = date1.get_day();
            int date2_day = date2.get_day();
            if (date1_day < date2_day) {
                return true;
            }
        }
    }
    return false;
}
