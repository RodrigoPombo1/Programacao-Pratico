#include "wc.h"

wcresult wc(const string& filename) {
    ifstream in (filename);
    wcresult res;
    res.lines = 0;
    res.words = 0;
    res.bytes = 0;
    for (string line; getline(in, line);) {
        res.lines++;
        res.bytes += line.length() + 1; // o + 1 é o \n
        istringstream iss (line); // iss = input string stream, podes chamar o que te apetecer        
        for (string word; iss >> word;) {
            res.words++;
        }
    }
    return res;
}

int main() {
    wcresult r = wc("p2_test5.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';
    return 0;
}