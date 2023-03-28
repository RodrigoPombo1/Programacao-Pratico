#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void stringtolower(string& word_cmp) {
    for (char& c : word_cmp) {
        c = tolower(c);
    }
}

int count(const string& fname, const string& word) {
    ifstream in (fname);
    string word_cmp = word;
    stringtolower(word_cmp);
    int c = 0;
    for (string s; in >> s;) {
        stringtolower(s);
        if (s == word_cmp) {
            c++;
        }
    }
    return c;
}