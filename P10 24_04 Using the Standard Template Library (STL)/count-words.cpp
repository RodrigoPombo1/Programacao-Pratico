#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

void show_vector(const vector<pair<string, size_t>>& count) {
  cout << "[ ";
  for (const auto& e : count) {
    cout << e.first << ":" << e.second << ' ';
  }
  cout << "]\n";
}

void count_words(const string& str, vector<pair<string, size_t>>& count) {
  string str_copy = str;
  transform(str_copy.begin(), str_copy.end(), str_copy.begin(), ::tolower);
  istringstream iss = istringstream(str_copy);
  string word;
  while (iss >> word) {
    bool found = false;
    for (pair<string, size_t>& element : count) {
      if (element.first == word) {
        element.second++;
        found = true;
        break;
      }
    }
    if (!found) {
      count.push_back({word, 1});
    }
  }
  sort(count.begin(), count.end(), [](const pair<string, size_t>& a, const pair<string, size_t>& b) {
    return a.first < b.first;
  });
}

int main() {
  { string s = "If you want to buy  buy  if you don't want to buy  bye bye";
  vector<pair<string, size_t>> count;
  count_words(s, count);
  show_vector(count); }
  return 0;
}