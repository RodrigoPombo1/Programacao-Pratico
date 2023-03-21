#include <string>
#include <vector>
#include <iostream>
using namespace std;

string longest_prefix(const vector<string>& v) {
    string str_res_prefix = v[0];
    for (string element : v) {
        bool equal_to_res = true;
        long unsigned int char_pos;
        for (char_pos = 0; char_pos < element.length() && char_pos < str_res_prefix.length(); char_pos++) {
            if (element[char_pos] != str_res_prefix[char_pos]) {
                equal_to_res = false;
                break;
            }
        }
        if (equal_to_res == false) {
            str_res_prefix = element.substr(0, char_pos);
        }

    }
    return str_res_prefix;
}

int main() {
    cout << "\"" << longest_prefix({ "sedatesingratiateconcomitant", "sedatesparleypoliteness", "sedateselbowsHahn", "sedatesgloweringimbecility's", "sedatesbuttershexing", "sedatesKwangju'smulch's", "sedatesunwiserN", "sedatesprepossessedboggles", "sedatesinterrelationshipdialings", "sedatesgropesNelsen's", "sedatesMayfaircondemnations" }) << "\"\n";
    return 0;
}
