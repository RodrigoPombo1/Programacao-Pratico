#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include <vector>
#include <iostream>
using namespace std;

void read_hours_worked(vector<Employee*> &employees) {
    for (size_t i = 0; i < employees.size(); i++) {
        HourlyEmployee* hourly_employee = dynamic_cast<HourlyEmployee*>(employees[i]);
        if (hourly_employee != nullptr) {
            double hours;
            cin >> hours;
            hourly_employee->set_hours(hours);
        }
    }
}

void HourlyEmployee::calculate_net_pay() {
    this->set_net_pay(wage_rate_ * hours_);
}

void SalariedEmployee::calculate_net_pay() {
    this->set_net_pay(salary_);
}


void calculate_pay(vector<Employee*> &employees) {
    for (size_t i = 0; i < employees.size(); i++) {
        employees[i]->calculate_net_pay();
    }
}


void print_checks(const vector<Employee*>& employees) {
    cout << "| ";
    for (size_t i = 0; i < employees.size(); i++) {
        employees[i]->print_check();
        cout << " | ";
    }
}