#include "alist.h"
#include <iostream>
using namespace std;


void append(alist* a, const alist* b) {
    int size_res = a->size + b->size;
    if (size_res == 0) {
        return;
    }
    int *res = new int[size_res];
    int i = 0;
    for (i = 0; i < a->size; i++) {
        res[i] = a->elements[i];
    }
    for (i = a->size; i < size_res; i++) {
        res[i] = b->elements[i - a->size];
    }
    delete [] a->elements;
    a->size = size_res;
    a->elements = res;
}

int main() {
    const int nA = 4;
    int eA[nA] = { 1, 2, 3, 4 };
    alist* a = build(nA, eA);
    const int nB = 3;
    int eB[nB] = { 5, 6, 7 };
    const alist* b = build(nB, eB);
    append(a, b);
    print(a);
    destroy(a);
    destroy(b);

    return 0;
}