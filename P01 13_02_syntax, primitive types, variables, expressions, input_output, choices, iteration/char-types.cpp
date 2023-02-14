#include <iostream>
using namespace std;

int main() {
    int chars = 0;
    int nums = 0;
    int other = 0;
    int n_chars;
    cin >> n_chars;
    for (int i = 0; i < n_chars; i++) {
        char current_chr;
        cin >> current_chr;
        if ('0' <= current_chr && current_chr <= '9') {
            nums++;
        }
        else if (('a' <= current_chr && current_chr <= 'z') || ('A' <= current_chr && current_chr <= 'Z')) {
            chars++;
        }
        else {
            other++;
        }
    }
    cout << chars << ' ' << nums << ' ' << other;
    return 0;
}