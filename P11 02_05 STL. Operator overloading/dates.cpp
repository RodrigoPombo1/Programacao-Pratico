#include "Date.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool operator<(const Date date1, const Date date2) {
    if (date1.getYear() < date2.getYear()) {
        return true;
    } else if (date1.getYear() == date2.getYear()) {
        if (date1.getMonth() < date2.getMonth()) {
        return true;
        } else if (date1.getMonth() == date2.getMonth()) {
        if (date1.getDay() < date2.getDay()) {
            return true;
        }
        }
    }
    return false;
}

ostream& operator<<(ostream& os, const Date date)  {
    int year = date.getYear();
    int month = date.getMonth();
    int day = date.getDay();
    if (year < 10) { 
        os << "000" << year;
    } else if (year < 100) {
        os << "00" << year;
    } else if (year < 1000) {
        os << "0" << year;
    } else {
        os << year;
    }
    os << "/";
    if (month < 10) {
        os << "0" << month;
    } else {
        os << month;
    }
    os << "/";
    if (day < 10) {
        os << "0" << day;
    } else {
        os << day;
    }
    return os;
}

int main() {
    { vector<Date> dates = { {2023,11,15}, {2021,12,8}, {2023,11,14} };
  sort(dates.begin(), dates.end());
  for (const auto& d : dates) cout << d << " ";
  cout << '\n'; }
  return 0;
}