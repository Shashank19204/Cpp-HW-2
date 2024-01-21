#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

class Fraction {
public:
  Fraction(int num = 0, int den = 1) {
    numerator = num;
    denominator = den;
  }

  Fraction add(const Fraction& other) {
    return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
  }

  Fraction subtract(const Fraction& other) {
    return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
  }

  Fraction multiply(const Fraction& other) {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
  }

  Fraction divide(const Fraction& other) {
    return Fraction(numerator * other.denominator, denominator * other.numerator);
  }

  double toDouble() const {
    return static_cast<double>(numerator) / denominator;
  }

  friend ostream& operator<<(ostream& out, const Fraction& f) {
    out << f.numerator << "/" << f.denominator;
    return out;
  }

  friend istream& operator>>(istream& in, Fraction& f) {
    char dummy;
    in >> f.numerator >> dummy >> f.denominator;
    f.simplify();
    return in;
  }

private:
  void simplify() {
    int div = gcd(numerator, denominator);
    numerator /= div;
    denominator /= div;
  }
};

int main() {
  Fraction f1(3, 4);
  Fraction f2(5, 6);

  cout << f1 << endl;
  cout << f2 << endl;

  Fraction f3 = f1.add(f2);
  Fraction f4 = f1.subtract(f2);
  Fraction f5 = f1.multiply(f2);
  Fraction f6 = f1.divide(f2);

  cout << f3 << endl;
  cout << f4 << endl;
  cout << f5 << endl;
  cout << f6 << endl;

  double f3_double = f3.toDouble();
  cout << f3_double << endl;

  return 0;
}

