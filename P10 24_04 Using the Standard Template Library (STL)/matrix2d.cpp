#include <iostream>
#include <vector>
using namespace std;

void show_vector(const vector<vector<int>>& v) {
  cout << "{";
  for (const auto& line : v) {
    cout << "{ ";
    for (const auto& elem : line)
      cout << elem << ' ';
    cout << "}";
  }
  cout << "}";
}

bool check_arguments(vector<vector<int>> &v, int n) {
  return (v.size() >= (long unsigned int)n && v[0].size() >= (long unsigned int)n) && n % 2;
}

bool max_filter(vector<vector<int>> &v, int n) {
  if (!check_arguments(v, n)) {
    return false;
  }
  vector<vector<int>> temp = v;
  for (long unsigned int i = 0; i < v.size(); i++) {
    for (long unsigned int j = 0; j < v[i].size(); j++) {
      int max = v[i][j];
      for (int k = - n/2; k <= n/2; k++) {
        for (int l = -n/2; l <= n/2; l++) {
          if ((int)v.size() > (int)i + k && (int)v[0].size() > (int)j + l && (int)i + k >= 0 && (int)j + l >= 0) {
            int current_number = v[i + k][j + l];
            if (current_number > max) {
              max = current_number;
            }
          }
        }
      }
      temp[i][j] = max;
    }
  }
  v = temp;
  return true;
}


int main() { 
  { vector<vector<int>> v = { {1,2,3}, {4,5,6}, {7,8,9} };
  bool b = max_filter(v, 3); cout << boolalpha << b;
  show_vector(v); cout << endl; }

  { vector<vector<int>> v =
  { { 8,5,4,2,1 },
    { 1,2,4,5,9 },
    { 3,6,3,7,3 },
    { 5,7,8,1,4 },
    { 9,1,2,6,5 } };
  bool b = max_filter(v, 3); cout << boolalpha << b;
  show_vector(v); cout << endl; }
  
  { vector<vector<int>> v = { { 8,5,4,2,1 }, { 9,1,2,6,5 } };
  bool b = max_filter(v, 3); cout << boolalpha << b;
  show_vector(v); cout << endl; }
  
  { vector<vector<int>> v =
    { { -8,-5,4,2,1,-1,7 },
      { -1,-2,4,5,9,0,4 },
      { -3,6,-3,-7,3,-10,-7 },
      { 5,7,8,1,4,-2,-31 },
      { -9,1,-2,6,5,-5,-16 } };
  bool b = max_filter(v, 3); cout << boolalpha << b;
  show_vector(v); cout << endl; }
  
  { vector<vector<int>> v =
    { { -8,-5,4,2,1,-1,7 },
      { -1,-2,4,5,9,0,4 },
      { -3,6,-3,-7,3,-10,-7 },
      { 5,7,8,1,4,-2,-31 },
      { -9,1,-2,6,5,-5,-16 } };
  bool b = max_filter(v, 5); cout << boolalpha << b;
  show_vector(v); cout << endl; }
  
  return 0;
}