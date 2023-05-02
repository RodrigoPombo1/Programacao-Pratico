#include <string>
#include <map>
using namespace std;

void replace(const map<char, char>& r, string& s) {
    for (char &c : s) {
        auto itr = r.find(c);
        if (itr != r.end()) {
            c = itr->second;
        }
    }
}