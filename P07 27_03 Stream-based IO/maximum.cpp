#include "show_file.h"
// #include <string>
// using namespace std;

void maximum(const string& input_fname, const string& output_fname) {
    ifstream file_input (input_fname);
    ofstream file_output (output_fname);
    double max;
    unsigned long int count = 0;
    for (string line; getline(file_input, line);) {
        line.erase(0, line.find_first_not_of(' '));
        line.erase(line.find_last_not_of(' ') + 1);
        if (line.empty()) {
            continue;
        }
        double current_number = stod(line);
        // para o caso em que não há max para comparar
        if (count == 0) {
            max = current_number;
        }
        if (max < current_number) {
            max = current_number;
        }
        // stringstream current_str_stream;
        // current_str_stream << setprecision(3) << current_number;
        // string current_str = current_str_stream.str(); // eu achava que era preciso passar para string para pôr no ficheiro :/
        file_output << fixed << setprecision(3) << current_number << endl;
        count++;
    }
    file_output << "count=" << count << "/max=" << fixed << setprecision(3) << max;
}