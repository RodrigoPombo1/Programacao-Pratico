#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T1, typename T2>
class Pair {
public:
    Pair(T1 first, T2 second) {
        this->first = first;
        this->second = second;
    }
    T1 get_first() {
        return first;
    }
    T2 get_second() {
        return second;
    }
    void show() {
        cout << "{" << first << "," << second << "}";
    }

private:
    T1 first;
    T2 second;
};

template <typename T1, typename T2>
void show(vector<Pair<T1, T2>> persons) {
    cout << "{";
    for (auto person : persons) {
        person.show();
    }
    cout << "}";
}

template <typename T1, typename T2>
void sort_by_first(vector<Pair<T1, T2>> &persons) {
    if (persons.size() == 0) {
        return;
    }
    sort(persons.begin(), persons.end(), [](Pair<T1, T2> a, Pair<T1, T2> b) {
        return a.get_first() < b.get_first();
    });
}

template <typename T1, typename T2>
void sort_by_second(vector<Pair<T1, T2>> &persons) {
    if (persons.size() == 0) {
        return;
    }
    sort(persons.begin(), persons.end(), [](Pair<T1, T2> a, Pair<T1, T2> b) {
        return a.get_second() < b.get_second();
    });
}

int main() {
  { vector<Pair<string, int>> persons = { {"Maria",17},{"Ana",21},{"Pedro",19} };
  sort_by_first(persons);
  show(persons); cout << '\n'; }

  { vector<Pair<string, int>> persons = { {"Ana",19},{"Rui",16} };
  sort_by_second(persons);
  show(persons); cout << '\n'; }
  return 0;
}