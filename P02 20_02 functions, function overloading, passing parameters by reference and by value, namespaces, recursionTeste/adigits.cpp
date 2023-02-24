int adigits(int a, int b, int c) {
    if (a >= b && b >= c) {
        return a * 100 + b * 10 + c;
    }
    else if (b >= a && a >= c) {
        return b * 100 + a * 10 + c;
    }
    else if (a >= c && c >= b) {
        return a * 100 + c * 10 + b;
    }
    else if (c >= a && a >= b) {
        return c * 100 + a * 10 + b;
    }
    else if (c >= b && b >= a) {
        return c * 100 + b * 10 + a;
    }
    else if (b >= c && c >= a) {
        return b * 100 + c * 10 + a;
    }
    return 1;
}