#include "Operation.h"
#include <cmath>
#include <iostream>
using namespace std;

class Sum : public Operation {
public:
    Sum(double op1, double op2) : Operation(op1, op2) {}
    int operation() const {
        return (int)get_op1() + (int)get_op2();  
    }    
};

class Power : public Operation {
public:
    Power(double op1, double op2) : Operation(op1, op2) {}
    int operation() const {
        return pow((int)get_op1(),(int) get_op2());  
    }    
};

int main() {
    { const Operation& s = Sum(2, 10); cout << s.operation() << ' '; 
  const Operation& p = Power(2, 10); cout << p.operation() << endl; }
    return 0;
}