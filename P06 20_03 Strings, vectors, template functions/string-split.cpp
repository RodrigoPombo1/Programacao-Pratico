#include "print_string.h"

void split(const string& s, vector<string>& v) {
    long unsigned int pos = 0;
    while (true) {
        long unsigned int pos_of_next_space = s.find(' ', pos);
        // se já não houver mais nenhum espaço a seguir a isto
        if (pos_of_next_space == string::npos) {
            // se o tamanho da substring não for 0 ou seja se a ultima posiçao não for a posiçao do ultimo espaço
            if (pos != s.length()) {
                v.insert(v.end(), s.substr(pos, s.length() - pos));
            }
            break; // == return
        }
        // se o tamanho da substr não for 0
        if (pos != pos_of_next_space) {
            v.insert(v.end(), s.substr(pos, pos_of_next_space - pos));
        }
        // temos de incrementar para passar o espaço
        pos = pos_of_next_space + 1;
    }
}

int main() {
    string s = "a ";
    vector<string> v;
    split(s, v);
    print(v);
    return 0;
}