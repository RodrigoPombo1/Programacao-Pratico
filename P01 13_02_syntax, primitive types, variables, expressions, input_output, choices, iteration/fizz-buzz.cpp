#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    for (int i = 1; i < a; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
        }
        else if (i % 3 == 0) {
            cout << "Fizz ";
        }
        else if (i % 5 == 0) {
            cout << "Buzz ";
        }
        else {
            cout << i << " ";
        }
    }
    if (a % 3 == 0 && a % 5 == 0) {
    }
    else if (a % 3 == 0) {
        cout << "Fizz";
    }
    else if (a % 5 == 0) {
        cout << "Buzz";
    }
    else {
        cout << a;
    }
    return 0;
}