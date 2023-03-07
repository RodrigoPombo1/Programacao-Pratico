#include "fraction.h"

fraction sum_two_fractions(fraction f1, fraction f2) {
    f1.num *= f2.den;
    f2.num *= f1.den;
    f1.den *= f2.den;
    f1.num += f2.num;
    return f1;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

fraction make_irreductible(fraction frac) {
    int divisor = gcd(frac.num, frac.den);
    frac.num /= divisor;
    frac.den /= divisor;
    if (frac.den < 0) {
        frac.num *= -1;
        frac.den *= -1;
    }
    return frac;
}

fraction sum(const fraction fa[], int n) {
    fraction res;
    res.num = 0;
    res.den = 1;
    for (int i = 0; i < n; i++) {
        res = sum_two_fractions(res, fa[i]);
    }
    return make_irreductible(res);
}
