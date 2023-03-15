#include <iostream>
using namespace std;

const char* longest(const char* pa[]) {
    int index_res = 0;
    int size_res = 0;
    for (int i = 0; pa[i] != nullptr; i++) {
        int j;
        for (j = 0; '\0' != pa[i][j]; j++) {
            continue;
        }
        if (j >= size_res) {
            index_res = i;
            size_res = j;
        }
    }
    return pa[index_res];
}

int main() {
    const char* pa[] = { "C++", nullptr };
    cout << "\"" << longest(pa) << "\"\n";
    return 0;
}