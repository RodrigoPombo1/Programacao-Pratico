#include <iostream>
using namespace std;

char lowercase_letter(char chr) {
    if ('A' <= chr && chr <= 'Z') {
        chr = chr - 'A' + 'a';
    }
    if ('a' <= chr && chr <= 'z') {
        return chr;
    }
    return '\0';
}

bool pangram(const string& s, string& m) {
    int check_letter [26] = { 0 };
    for (int i = 0; s[i] != '\0'; i++) {
        char current_letter = lowercase_letter(s[i]);
        if (current_letter == '\0') {
            continue; 
        }
        check_letter[current_letter - 'a'] = 1;
    }
    int res_counter = 0;
    for (int i = 0; i < 26; i++) {
        if (check_letter[i] == 1) {
            res_counter++;
            continue;
        }
        m.push_back('a' + i);
    }
    if (res_counter == 26) {
        return true;
    }
    return false;
}

int main() {
string s = "A quick brown fox jumps over a classy dog";
  string m = "";
  bool r = pangram(s, m);
  cout << '\"' << s << "\" " 
       << boolalpha << r << " \"" << m << "\"\n";
    return 0;
}