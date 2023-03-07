int nrl(const char s[], char low[]) {
    // count the number of times each character appears on the str
    int low_count[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for (int i = 0; s[i] != '\0'; i++) {
        char current_chr = s[i];
        // check for spaces
        if (current_chr == ' ') {
            continue;
        }
        // check for uppercase letters
        if ('A' <= current_chr && current_chr <= 'Z') {
            current_chr = (char) ('a' + current_chr - 'A');
        }
        low_count[current_chr - 'a']++;
    }
    // see which characters to add to the final str, while simultaneously counting the number of characters in that str
    int res = 0;
    bool flag = false;
    for (int i = 0; i < 26; i++) {
        if (low_count[i] == 1) {
            low[res] = (char) ('a' + i);
            res++;
            flag = true;
        }
    }
    if (flag == false) {
        low[0] = '\0';
    }
    return res;
}


#include <iostream>
using namespace std;

int main() {
    const char s[] = "";
    char l[27] = { -1 };
    int r = nrl(s, l);
    cout << '\"' << s << "\" " << r << " \"" << l << "\"\n";

    const char t[] = "  F C U P  F E U P  Porto  ";
    l[27] = { -1 };
    r = nrl(t, l);
    cout << '\"' << t << "\" " << r << " \"" << l << "\"\n";

    const char u[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ";
    l[27] = { -1 };
    r = nrl(u, l);
    cout << '\"' << u << "\" " << r << " \"" << l << "\"\n";

    const char v[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ABc DeF gHi JkL mNo PqR sTu VwX Yz";
    l[27] = { -1 };
    r = nrl(v, l);
    cout << '\"' << v << "\" " << r << " \"" << l << "\"\n";

    const char w[] = "The quick brown fox jumps over the lazy dog";
    l[27] = { -1 };
    r = nrl(w, l);
    cout << '\"' << w << "\" " << r << " \"" << l << "\"\n";

    return 0;
}