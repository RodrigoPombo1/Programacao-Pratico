#include "fraction.h"

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

fraction make_irreductible(fraction res) {
    int res_gcd = gcd(res.num, res.den);
    res.num /= res_gcd;
    res.den /= res_gcd;
    //tratar dos sinais
    if (res.den < 0) {
        res.num *= -1;
        res.den *= -1;
    }
    return res;
}

fraction add(fraction a, fraction b) {
    a.num *= b.den;
    a.den *= b.den;
    b.num *= a.den;
    fraction res;
    res.num = a.num + b.num;
    res.den = a.den;
    res = make_irreductible(res);
    return res;
}

fraction mul(fraction a, fraction b) {
    fraction res;
    res.num = a.num * b.num;
    res.den = a.den * b.den;
    res = make_irreductible(res);
    return res;
}

int main() {
    return 0;
}