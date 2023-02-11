#include <iostream>
using namespace std;

int main() {
  int a;
  cin >> a;
  // TODO: change initial value of i and fix test condition
  for (int i = 1; i < a; i++) {
    if (a%i == 0) {
      cout << i << ' ';
    }
  }
  return 0;
}