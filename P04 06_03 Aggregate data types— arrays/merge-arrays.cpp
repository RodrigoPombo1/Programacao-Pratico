#include "print_array.h"

void merge_arrays(const int a[], int na, const int b[], int nb, int c[]) {
    for (int i = 0, counter_a = 0, counter_b = 0; i <= na + nb - 1; i++) {
        if (counter_a >= na) {
            c[i] = b[counter_b];
            counter_b++;
            continue;
        }
        if (counter_b >= nb) {
            c[i] = a[counter_a];
            counter_a++;
            continue;
        }
        if (a[counter_a] <= b[counter_b]) {
            c[i] = a[counter_a];
            counter_a++;
            continue;
        }
        if (a[counter_a] > b[counter_b]) {
            c[i] = b[counter_b];
            counter_b++;
        }
    }
}