#include "print_vector.h"

template <typename T>
void normalise(vector<T>& v, const T& min, const T& max) {
    for (T& element : v) {
        if (element < min) {
            element = min;
        }
        if (element > max) {
            element = max;
        }
    }
}

int main() {
    vector<int> v { 1, 2, 3, 4, 5 };
    normalise(v, 3, 4);
    print(v);
    return 0;
}