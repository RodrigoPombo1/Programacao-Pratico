#include "time_of_day.h"

time_of_day tick(time_of_day t) {
    t.m++;
    if (t.m > 59) {
        t.m -= 60;
        t.h++;
    }
    if (t.h > 23) {
        t.h -= 24;
    }
    return t;
}

int main() {
    cout << tick({ 0, 0 }) << '\n';
    cout << tick({ 12, 30 }) << '\n';
    cout << tick({ 12, 59 }) << '\n';
    cout << tick({ 23, 59 }) << '\n';
    cout << tick(tick(tick({ 23, 59 }))) << '\n';
    return 0;
}