#include <iostream>
using namespace std;

bool check_leap_year(int year) {
    if (year % 400 == 0) {
        return true;
    }
    if (year % 100 == 0) {
        return false;
    }
    if (year % 4 == 0) {
        return true;
    }
    return false;
}

int days_in_month(int month, bool is_leap_year) {
    if (month == 2 && is_leap_year == true) {
        return 29;
    }
    if (month == 2 && is_leap_year == false) {
        return 28;
    }
    if (month < 8) {
        if (month % 2 == 0) {
            return 30;
        }
        else {
            return 31;
        }
    }
    if (month % 2 == 0) {
        return 31;
    }
    return 30;
}

void advance(int delta, int& d, int& m, int& y) {
    d += delta;
    bool lycheck = check_leap_year(y);
    int days_month = days_in_month(m, lycheck);
    while (d > days_month) {
        d -= days_month;
        m++;
        if (m == 13) {
            m = 1;
            y++;
        }
        lycheck = check_leap_year(y);
        days_month = days_in_month(m, lycheck);
    }
    return;
}

int main() {
    int d = 2, m = 12, y = 1900;
    advance(365 + 5, d, m, y);
    cout << d << ' ' << m << ' ' << y << '\n';
    return 0;
}
