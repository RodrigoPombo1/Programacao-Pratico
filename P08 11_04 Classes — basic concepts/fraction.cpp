#include <numeric>
// given functions to use in the Fraction class definition

#include <iostream>
#include <cmath>
using namespace std;


class Fraction {
    public:
        Fraction() : Fraction(0, 1) {}
        Fraction(int n, int d) {
            int g = Fraction::gcd(n, d);
            numerator_ = n/g;
            denominator_ = d/g;
        }

        int gcd(int numerator_, int denominator_);
        void normalise();
        void write() const;

        Fraction sum(Fraction f) {
            Fraction result(numerator_ * f.denominator() + denominator_ * f.numerator(),
                            denominator_ * f.denominator());
            result.normalise();
            return result;
        }
        Fraction sub(Fraction f) {
            Fraction result(numerator_ * f.denominator() - denominator_ * f.numerator(),
                            denominator_ * f.denominator());
            result.normalise();
            return result;
        }
        Fraction mul(Fraction f) {
            Fraction result(numerator_ * f.numerator(), denominator_ * f.denominator());
            result.normalise();
            return result;
        }
        Fraction div(Fraction f) {
            Fraction result(numerator_ * f.denominator(), denominator_ * f.numerator());
            result.normalise();
            return result;
        }
        int numerator() {
            return numerator_;
        }
        int denominator() {
            return denominator_;
        }
    private:
        int numerator_;
        int denominator_;
};

//! Compute the gcd of two numbers.
int Fraction::gcd(int a, int b) {
  while (b != 0) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

//! Normalize a fraction.
void Fraction::normalise() {
  int g = gcd(numerator_, denominator_);
  numerator_ /= g;
  denominator_ /= g;
  if (denominator_ < 0) {
    numerator_ = - numerator_;
    denominator_ = - denominator_;
  }
}

// shows fraction on the screen
void Fraction::write() const {
  cout << numerator_ << '/' << denominator_;
}