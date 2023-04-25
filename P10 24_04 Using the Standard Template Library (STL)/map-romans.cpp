#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<pair<char, unsigned>> roman_to_int = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

unsigned single_digit_in_roman_to_arab(const char& roman) {
    for (auto& digit : roman_to_int) {
        if (digit.first == roman) {
            return digit.second;
        }
    }
    return 0;
}

bool check_is_roman_digit_smaller(const char& roman1, const char& roman2) {
    return single_digit_in_roman_to_arab(roman1) < single_digit_in_roman_to_arab(roman2);
}

unsigned roman_to_arab(const string& roman) {
    unsigned res = 0;
    long unsigned int counter_of_same_digits_followed = 0;
    if (roman.size() == 0) {
        return 0;
    }
    char previous_digit = roman[0];
    for (long unsigned int i = 0; i < roman.size(); i++) {
        if (previous_digit == roman[i]) {
            counter_of_same_digits_followed++;
            continue;
        }
        if (check_is_roman_digit_smaller(previous_digit, roman[i])) {
            res -= counter_of_same_digits_followed * single_digit_in_roman_to_arab(previous_digit);
        } else {
            res += counter_of_same_digits_followed * single_digit_in_roman_to_arab(previous_digit);
        }
        previous_digit = roman[i];
        counter_of_same_digits_followed = 1;
    }
    res += counter_of_same_digits_followed * single_digit_in_roman_to_arab(previous_digit);
    return res;
}

int main() {
    { string r = "XV"; cout << roman_to_arab(r) << '\n'; }
    { string r = "LXXXIV"; cout << roman_to_arab(r) << '\n'; }
    { string r = "CMLXIV"; cout << roman_to_arab(r) << '\n'; }
    { string r = "MMMCMXCIX"; cout << roman_to_arab(r) << '\n'; }
    { string r = "MMMDCCCLXXXVIII"; cout << roman_to_arab(r) << '\n'; }
    return 0;
}