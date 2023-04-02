#include "show_file.h"

double get_median_from_vec(vector<double> vec) {
    long unsigned int size = vec.size();
    sort(vec.begin(), vec.end());
    if (size % 2) {
        return vec[size/2];
    }
    return (vec[size/2 - 1] + vec[size/2]) * 0.5;
}

void calc_medians(const string& input_fname, const string& output_fname) {
    ifstream file_input (input_fname);
    ofstream file_output (output_fname);
    for (string line; getline(file_input, line);) {
        istringstream line_string_stream(line);
        string word;
        line_string_stream >> word;
        if (word.size() > 0 && word[0] == '#') {
            continue;
        }
        file_output << word;
        vector<double> line_numbers = {};
        while (line_string_stream >> word) {
            if (word[0] == '#') {
                break;
            }
            line_numbers.push_back(stod(word));
        }
        if (line_numbers.empty()) {
            continue;
        }
        double current_line_median = get_median_from_vec(line_numbers);
        file_output << ' ' << fixed << setprecision(1) << current_line_median << endl;
    }
}