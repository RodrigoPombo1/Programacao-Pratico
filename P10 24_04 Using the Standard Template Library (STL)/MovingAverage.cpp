#include "MovingAverage.h"
using namespace std;

MovingAverage::MovingAverage(size_t n) {
    this->n_ = n;
}

void MovingAverage::update(double value) {
    this->values_.push_back(value);
    if (this->values_.size() > this->n_) {
        this->values_.pop_front();
    }
}

double MovingAverage::get() const {
    double sum = 0;
    for (double value : this->values_) {
        sum += value;
    }
    return sum / this->values_.size();
}