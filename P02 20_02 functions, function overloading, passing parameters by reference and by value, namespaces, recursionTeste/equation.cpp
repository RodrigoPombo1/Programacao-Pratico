#include <iostream>
#include <math.h>
using namespace std;

double get_solution(int a, int b, double delta, int sign) {
    return (-b + sign * sqrt(delta)) / (2 * a);
}

int solve_eq(int a, int b, int c, double& x1, double& x2) {
    double delta = pow((double) b, 2) - 4 * (double) a * (double) c;
    if (delta < 0) {
        x1 = nan("");
        x2 = nan("");
        return 0;
    }
    if (delta == 0) {
        x1 = get_solution(a, b, delta, 1);
        x2 = nan("");
        return 1;
    }
    x2 = get_solution(a, b, delta, 1);
    x1 = get_solution(a, b, delta, -1);
    return 2;
}

int main() {
    return 0;
}