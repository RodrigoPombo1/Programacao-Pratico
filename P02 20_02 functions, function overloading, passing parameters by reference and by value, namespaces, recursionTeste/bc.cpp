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
