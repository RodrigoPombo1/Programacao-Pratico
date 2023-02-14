#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    bool flag;
    int i, j;
    for (i = 2; i < a; i++) {
        flag = true;
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            cout << i << ' ';
        }
    }
    if (a > 1) {
        flag = true;
        for (int j = 2; j < i; j++) {
        if (i % j == 0) {
            flag = false;
            break;
        }
        }
        if (flag == true) {
            cout << i;
        }
    }
    return 0;
}