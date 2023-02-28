#include <iostream>
using namespace std;

bool check_prime(int n) {
    if (n == 0 || n == 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    for (int i = 2; i < (n / 2 + 1); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool check_pernicious(int n) {
    int num_1s = 0;
    while (n != 0) {
        if (n % 2 != 0) {
            num_1s++;
        }
        n = n / 2;
    }
    if (check_prime(num_1s)) {
        return true;
    }
    return false;
}

int main() {
    int a, b;
    cin >> a;
    cin >> b;
    for (int i = a; i < b; i++) {
        if (check_prime(i) && check_pernicious(i)) {
            cout << i << " ";
        }
    }
    if (check_prime(b) && check_pernicious(b)) {
            cout << b;
        }
    return 0;
}
