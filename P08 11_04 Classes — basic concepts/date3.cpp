#include "Date3.h"
#include <iomanip>
#include <sstream>
using namespace std;

Date::Date() : Date::Date(1, 1, 1) {}

Date::Date(int year, int month, int day) {
    if ((year < 1 || year > 9999) 
    || (month < 1 || month > 12) 
    || ((day < 1 || day > 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
    || ((day < 1 || day > 28) && month == 2 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))) 
    || ((day < 1 || day > 30) && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))) {
        yyyymmdd = "00000000";
        return;
    }
    ostringstream yyyymmdd_oss;
    yyyymmdd_oss << std::setfill('0')
            << std::setw(4) << year
            << std::setw(2) << month
            << std::setw(2) << day;
    yyyymmdd = yyyymmdd_oss.str();
}

bool check_year(const string& year_month_day) {
    istringstream iss (year_month_day);
    string year;
    getline(iss, year, '/');
    size_t year_length = year.length();
    if (year_length > 4) {
        return false;
    }
    for (long unsigned int i = 0; i < year_length; i++) {
        if (year[i] < '0' || year[i] > '9') {
            return false;
        }
    }
    return true;
}

bool check_month(const string& year_month_day) {
    istringstream iss (year_month_day);
    string month;
    getline(iss, month, '/'); // year
    getline(iss, month, '/');
    size_t month_length = month.length();
    if (month_length > 2) {
        return false;
    }
    for (long unsigned int i = 0; i < month_length; i++) {
        if (month[i] < '0' || month[i] > '9') {
            return false;
        }
    }
    int month_int = stoi(month);
    if (month_int < 1 || month_int > 12) {
        return false;
    }
    return true;
}

bool check_day(const string& year_month_day) {
    istringstream iss (year_month_day);
    string year;
    string month;
    string day;
    getline(iss, year, '/');
    getline(iss, month, '/');
    getline(iss, day);
    size_t day_length = day.length();
    if (day_length > 2) {
        return false;
    }
    for (long unsigned int i = 0; i < day_length; i++) {
        if (day[i] < '0' || day[i] > '9') {
            return false;
        }
    }
    int day_int = stoi(day);
    if ((day_int < 1 || day_int > 31) && (month == "1" || month == "3" || month == "5" || month == "7" || month == "8" || month == "10" || month == "12")) {
        return false;
    }
    int year_int = stoi(year); // não é preciso verificar se o ano é válido, pq se não for, o programa não chega aqui
    if ((day_int < 1 || day_int > 28) && month == "2" && (year_int % 4 != 0 || (year_int % 100 == 0 && year_int % 400 != 0))) { // verfica se é um leap year
        return false;
    }
    if ((day_int < 1 || day_int > 30) && (month == "2" || month == "4" || month == "6" || month == "9" || month == "11")) {
        return false;
    }
    return true;
}

Date::Date(const string& year_month_day) {
    if (check_year(year_month_day) && check_month(year_month_day) && check_day(year_month_day)) {
        istringstream iss (year_month_day);
        string year;
        string month;
        string day;
        getline(iss, year, '/');
        getline(iss, month, '/');
        getline(iss, day);
        ostringstream yyyymmdd_oss;
        yyyymmdd_oss << std::setfill('0')
                << std::setw(4) << year
                << std::setw(2) << month
                << std::setw(2) << day;
        yyyymmdd = yyyymmdd_oss.str();
    } else {
        yyyymmdd = "00000000";
    }
}

int Date::get_year() const {
    return stoi(yyyymmdd.substr(0, 4));
}

int Date::get_month() const {
    return stoi(yyyymmdd.substr(4, 2));
}

int Date::get_day() const {
    return stoi(yyyymmdd.substr(6, 2));
}

bool Date::is_valid() const {
    if (get_year() == 0 || get_month() == 0 || get_day() == 0) {
        return false;
    }
    return true;
}

int main() {
    Date d1; d1.write(); cout << (d1.is_valid() ? "" : "-invalid") << endl;
    Date d2(2022, 4, 31); d2.write(); cout << (d2.is_valid() ? "" : "-invalid") << endl;
    Date d3("2ooo/2/28"); d3.write(); cout << (d3.is_valid() ? "" : "-invalid") << endl;
    Date d4("1900/1/1"); d4.write(); cout << (d4.is_valid() ? "" : "-invalid") << endl;
    Date d5("2022#12#31"); d5.write(); cout << (d5.is_valid() ? "" : "-invalid") << endl;
    return 0;
}