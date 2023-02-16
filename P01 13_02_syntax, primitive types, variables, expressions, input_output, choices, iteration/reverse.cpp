#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0;
    }
    int output;
    while (n > 0) {
        output = n % 10;
        if (output != 0) {
            cout << output;
        }
        n = n / 10;
    }
    return 0;
}