void trim(char s[]) {
    bool startf = false;
    int start = 0;
    int last_non_space_char = 0;
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (startf == false && s[i] != ' ') {
            startf = true;
            start = i;
        }
        if (s[i] == ' ') {
            last_non_space_char++;
            continue;
        }
        last_non_space_char = 0;
    }
    for (int j = start; j < i - last_non_space_char; j++) {
        s[j - start] = s[j];
    }
    s[i - last_non_space_char - start] = '\0';
}

#include <iostream>
using namespace std;

int main() {
    // char s[] = " abc! def? ";
    // cout << "\"" << s << "\" => ";
    // trim(s);
    // cout << "\"" << s << "\"\n";

    char s[] = "    abc def";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n";
    return 0;
}