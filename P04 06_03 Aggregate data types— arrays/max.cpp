int max(const int a[], int n) {
    int max_int = a[0];
    for (int i = 1; i < n; i++) {
        if (max_int < a[i]) {
            max_int = a[i];
        }
    }
    return max_int;
}