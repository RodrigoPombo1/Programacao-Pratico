#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
using namespace std;

template <typename Itr> 
string to_string(Itr start, Itr end) {
    string s = "[ ";
    for (Itr p = start; p != end; p++) {
        ostringstream temp = ostringstream();
        temp << *p;
        s += temp.str() + ' ';
    }
    s += ']';
    return s;
}

template <typename Itr, typename T> 
int replace(Itr start, Itr end, const T& a, const T& b){
    int number_of_elements_replaced = 0;
    for (Itr p = start; p != end; p++) {
        if (*p == a) {
            *p = b;
            number_of_elements_replaced++;
        }
    }
    return number_of_elements_replaced;
}
