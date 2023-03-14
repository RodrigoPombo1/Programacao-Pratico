#include <iostream>
using namespace std;

char* duplicate(const char s[]) {
    int sizeof_s = 0; 
    for (int i = 0; s[i] != '\0'; i++) {
        sizeof_s++;
    }
    char* s2 = new char[sizeof_s + 1];
    for (int i = 0; i < sizeof_s; i++) {
        s2[i] = s[i];
    }
    s2[sizeof_s] = '\0';
    return s2;
}

int main() {
    char* s = duplicate("a");
    cout << "\"" << s << "\"\n";
    delete [] s;

    char* s1 = duplicate("0123 456 789 @ abc");
    cout << "\"" << s1 << "\"\n";
    delete [] s1;

    char* s2 = duplicate("C++");
    cout << "\"" << s2 << "\"\n";
    delete [] s2;

    return 0;
}