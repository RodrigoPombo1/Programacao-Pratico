unsigned long factorial(unsigned long n) {
    unsigned long result = 1;
    for (unsigned long i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

unsigned long bc(unsigned long n, unsigned long k){
    return factorial(n) / (factorial(k) * factorial(n-k));
}

unsigned long bell(unsigned long n) {
    if (n <= 1) {
        return 1;
    }
    unsigned long result = 0;
    for (unsigned long k = 0; k <= n - 1; k++) {
        result += bc(n - 1, k) * bell(k);
    }
    return result;
}