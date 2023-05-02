#include <string>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;

void show_map(const map<string, size_t>& count) {
  cout << "[ ";
  for (const auto& e : count) {
    cout << e.first << ":" << e.second << ' ';
  }
  cout << "]\n";
}

void count_words(const string& str, map<string, size_t>& count) {
    istringstream iss(str);
    string word;
    while (iss >> word) {
        for (char &c : word) c=tolower(c);
        count[word]++;
    }
}