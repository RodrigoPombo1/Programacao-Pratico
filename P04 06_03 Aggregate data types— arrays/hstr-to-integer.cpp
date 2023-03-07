unsigned long hstr_to_integer(const char hstr[]) {
    unsigned long res = 0;
    for (int i = 0; hstr[i] != '\0'; i++) {
        char chr = hstr[i];
        int val;
        if ('0' <= chr && chr <= '9') {
            val = chr - '0';
        }
        else if ('a' <= chr && chr <= 'f') {
            val = chr - 'a' + 10;
        }
        else {
            val = chr - 'A' + 10;
        }
        res = res * 16 + val;
    }
    return res;
}

#include <iostream>
using namespace std;

int main() {
    cout << hstr_to_integer("0") << '\n';
    cout << hstr_to_integer("A") << '\n';
    cout << hstr_to_integer("19") << '\n';
    cout << hstr_to_integer("fF") << '\n';
    cout << hstr_to_integer("CafeBabe2022") << '\n';
    return 0;
}