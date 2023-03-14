#include "print_array.h"

int* merge_arrays(const int a[], int na, const int b[], int nb) {
    int* res = new int[na + nb];
    int count_a = 0;
    int count_b = 0;
    int count_res = 0;
    while (count_a < na && count_b < nb) {
        if (a[count_a] <= b[count_b]) {
            res[count_res] = a[count_a];
            count_a++;
            count_res++;
            continue;
        }
        res[count_res] = b[count_b];
        count_b++;
        count_res++;
    }
    if (count_a == na) {
        while (count_b < nb) {
            res[count_res] = b[count_b];
            count_b++;
            count_res++;
        }
        return res;
    }
    while (count_a < na) {
        res[count_res] = a[count_a];
        count_a++;
        count_res++;
    }
    return res;
}

int main() {
    const int NA = 6, NB = 4;
    int a[NA] = { 0, 3, 5, 6, 8, 9};
    int b[NB] = { 1, 2, 4, 7};
    int* c = merge_arrays(a, NA, b, NB);
    print_array(c, NA+NB);
    delete [] c;
    return 0;
}