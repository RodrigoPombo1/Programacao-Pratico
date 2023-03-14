#include <algorithm>
#include <iostream>
using namespace std;

int median(const int a[], int n) {
    int* tmp = new int[n];
    for (int i = 0; i < n; i++) {
        tmp[i] = a[i];
    }
    sort(tmp, tmp + n);
    if (n % 2 == 1) {
        int aux = tmp[n/2];
        delete [] tmp;
        return aux;
    }
    int aux = (tmp[n/2 - 1] + tmp[n/2]) / 2;
    delete [] tmp;
    return aux;
}

int main() {
    const int n = 5; 
    int a[n] { 10, -10, 0, 12, 11 };
    cout << median(a, n) << '\n';
    return 0;
}