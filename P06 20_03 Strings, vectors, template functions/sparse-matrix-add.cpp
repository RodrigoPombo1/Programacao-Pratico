#include "smatrix.h"

bool check_same_pos(sm_entry element_a, sm_entry element_b) {
    if (element_a.row == element_b.row && element_a.col == element_b.col) {
        return true;
    }
    return false;
}

bool position_smaller_than(sm_entry element_a, sm_entry element_b) {
    if ((element_a.row < element_b.row)||( element_a.row == element_b.row && element_a.col < element_b.col)) {
        return true;
    }
    return false;
}

void sum(const smatrix& a, const smatrix& b, smatrix& r) {
    long unsigned int pos_a = 0;
    long unsigned int pos_b = 0;
    long unsigned int a_length = a.size();
    long unsigned int b_length = b.size();
    while (pos_a < a_length && pos_b < b_length) {
        if (check_same_pos(a[pos_a], b[pos_b])) {
            int aux = a[pos_a].value + b[pos_b].value;
            if (aux != 0) {
                r.insert(r.end(), { a[pos_a].row, a[pos_a].col, aux });
            }
            pos_a++;
            pos_b++;
            continue;
        }
        if (position_smaller_than(a[pos_a], b[pos_b])) {
            r.insert(r.end(), a[pos_a]);
            pos_a++;
            continue;
        }
        r.insert(r.end(), b[pos_b]);
        pos_b++;
    }
    while (pos_a < a_length) {
        r.insert(r.end(), a[pos_a]);
        pos_a++;
    }
    while (pos_b < b_length) {
        r.insert(r.end(), b[pos_b]);
        pos_b++;
    }
}

int main() {
    smatrix r;
  sum({ {0, 0, 1}, {1, 0, 1} },
      { {0, 3, 1}, {0, 50, 1} },
      r);
  print(r);
    return 0;
}