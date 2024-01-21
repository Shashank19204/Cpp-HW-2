#include <iostream>

using namespace std;

class Figure {
public:
  virtual double calcArea() const = 0;
  virtual double calcPerimeter() const = 0;
};

class Triangle : public Figure {
private:
  double side1, side2, side3;

public:
  Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

  double calcArea() const override {
    double s = (side1 + side2 + side3) / 2.0;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
  }

  double calcPerimeter() const override {
    return side1 + side2 + side3;
  }
};

class Rectangle : public Figure {
private:
  double width, height;

public:
  Rectangle(double w, double h) : width(w), height(h) {}

  double calcArea() const override {
    return width * height;
  }

  double calcPerimeter() const override {
    return 2 * (width + height);
  }
};

class Circle : public Figure {
private:
  double radius;

public:
  Circle(double r) : radius(r) {}

  double calcArea() const override {
    return pi * radius * radius;
  }

  double calcPerimeter() const override {
    return 2 * pi * radius;
  }
};

int main() {
  Triangle triangle(3, 4, 5);
  Rectangle rectangle(10, 5);
  Circle circle(2);

  cout << "Triangle area: " << triangle.calcArea() << endl;
  cout << "Triangle perimeter: " << triangle.calcPerimeter() << endl;

  cout << "Rectangle area: " << rectangle.calcArea() << endl;
  cout << "Rectangle perimeter: " << rectangle.calcPerimeter() << endl;

  cout << "Circle area: " << circle.calcArea() << endl;
  cout << "Circle perimeter: " << circle.calcPerimeter() << endl;

  return 0;
}
