#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

double average(const string& fname) {
    ifstream file_input (fname);
    double res = 0;
    int count = 0;
    while (!file_input.eof()) {
        double current_double;
        if (file_input >> current_double) {
            count++;
            res += current_double;
        } else {
            file_input.clear();
            file_input.ignore(1);
        }
    }
    return res / count;
}

int main() {
    double m = average("p6_test2.txt");
    cout << fixed << setprecision(2) << m << '\n';
    return 0;
}