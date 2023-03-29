#include "print.h"

void string_convert_to_uppercase(string& str) {
    for (char& c : str) {
        c = toupper(c);
    }
}

void normalise(const string& input_fname, const string& output_fname) {
    ifstream file_input (input_fname);
    ofstream file_output (output_fname);
    for (string line; getline(file_input, line);) {
        line.erase(0, line.find_first_not_of(' '));
        line.erase(line.find_last_not_of(' ') + 1); // + 1 pq n queres apagar o último que n é espaço
        if (line.length()) { // também podias fazer com !line.empty()
            string_convert_to_uppercase(line);
            file_output << line << endl;
        }
    }    
}