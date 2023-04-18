#include <iostream>
#include "Date.h"

Date::Date() : Date(1, 1, 1) {}
Date::Date(int year, int month, int day) {
    year_ = year;
    month_ = month;
    day_ = day;
}
bool Date::is_before(const Date& date) const {
    if (year_ < date.year_) {
        return true;
    }
    if (year_ > date.year_) {
        return false;
    }
    // if (year_ == date.year_)
    if (month_ < date.month_) {
        return true;
    }
    if (month_ > date.month_) {
        return false;
    }
    // if (month_ == date.month_)
    if (day_ < date.day_) {
        return true;
    }
    return false;
}