#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
    double res = 0;
    int k;
    int d;
    cin >> k;
    cin >> d;
    for (double i = 0; i <= k; i++) {
        res += pow(-1.0, i) / (2*i + 1);
    }
    res *= 4;
    cout << fixed << setprecision(d) << res;
    return 0;
}