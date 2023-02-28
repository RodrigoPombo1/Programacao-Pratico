#include "complex.h"
#include <math.h>
using namespace std;

void add(const complex& a, const complex& b, complex& r) {
    r.x = a.x + b.x;
    r.y = a.y + b.y;
}

void mul(const complex& a, const complex& b, complex& r) {
    r.x = a.x * b.x - a.y * b.y;
    r.y = a.x * b.y + a.y * b.x;
}

void mandelbrot(const complex& c, unsigned int n, complex& z_n) {
    if (n == 0) {
        z_n.x = 0;
        z_n.y = 0;
        return;
    }
    complex r;
    mandelbrot(c, n - 1, r);
    mul(r, r, z_n);
    add(z_n, c, r);
    z_n = r;
    return;
}

int main() {
    complex z_n;
    mandelbrot({-1.2, 0.4}, 7, z_n);
    cout << z_n << '\n';
    
    mandelbrot({1, 1}, 2, z_n);
    cout << z_n << '\n';

    return 0;
}