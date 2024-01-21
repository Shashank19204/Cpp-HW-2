#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

class Fraction {
  int numerator;
  int denominator;

  public:
    Fraction(int num = 0, int den = 1) {
      numerator = num;
      denominator = den;
    }

  // Getter and Setter for numerator
  int getNumerator() const {
    return numerator;
  }
  void setNumerator(int num) {
    numerator = num;
  }

  // Getter and Setter for denominator
  int getDenominator() const {
    return denominator;
  }
  void setDenominator(int den) {
    denominator = den;
  }

  // Overloaded compound assignment operators
  Fraction & operator += (const Fraction & other) {
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator *= other.denominator;
    simplify();
    return * this;
  }

  Fraction & operator -= (const Fraction & other) {
    numerator = numerator * other.denominator - other.numerator * denominator;
    denominator *= other.denominator;
    simplify();
    return * this;
  }

  Fraction & operator *= (const Fraction & other) {
    numerator *= other.numerator;
    denominator *= other.denominator;
    simplify();
    return * this;
  }

  Fraction & operator /= (const Fraction & other) {
    numerator *= other.denominator;
    denominator *= other.numerator;
    simplify();
    return * this;
  }

  // Overloaded arithmetic operators
  Fraction operator + (const Fraction & other) const {
    Fraction result = * this;
    result += other;
    return result;
  }

  Fraction operator - (const Fraction & other) const {
    Fraction result = * this;
    result -= other;
    return result;
  }

  Fraction operator * (const Fraction & other) const {
    Fraction result = * this;
    result *= other;
    return result;
  }

  Fraction operator / (const Fraction & other) const {
    Fraction result = * this;
    result /= other;
    return result;
  }

  // Overloaded comparison operators
  bool operator == (const Fraction & other) const {
    return numerator == other.numerator && denominator == other.denominator;
  }

  bool operator != (const Fraction & other) const {
    return !( * this == other);
  }

  // Overloaded assignment operator
  Fraction & operator = (const Fraction & other) {
    if (this != & other) {
      numerator = other.numerator;
      denominator = other.denominator;
    }
    return * this;
  }

  // Overloaded << and >> operators
  friend ostream & operator << (ostream & out,
    const Fraction & f) {
    out << f.numerator << "/" << f.denominator;
    return out;
  }

  friend istream & operator >> (istream & in, Fraction & f) {
    char dummy;
    in >> f.numerator >> dummy >> f.denominator;
    f.simplify();
    return in;
  }

  // Function to convert fraction to double
  double toDouble() const {
    return static_cast < double > (numerator) / denominator;
  }

  private:
    // Function to simplify the fraction
    void simplify() {
      int div = gcd(numerator, denominator);
      numerator /= div;
      denominator /= div;
    }
};

int main() {
  // Testing the Fraction class
  Fraction f1(3, 4);
  Fraction f2(5, 6);

  cout << "f1: " << f1 << endl;
  cout << "f2: " << f2 << endl;

  Fraction f3 = f1 + f2;
  Fraction f4 = f1 - f2;
  Fraction f5 = f1 * f2;
  Fraction f6 = f1 / f2;

  cout << "f3 = f1 + f2: " << f3 << endl;
  cout << "f4 = f1 - f2: " << f4 << endl;
  cout << "f5 = f1 * f2: " << f5 << endl;
  cout << "f6 = f1 / f2: " << f6 << endl;

  double f3_double = f3.toDouble();
  cout << "f3_double: " << f3_double << endl;

  return 0;
}
