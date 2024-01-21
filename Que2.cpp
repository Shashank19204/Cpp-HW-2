#include <iostream>

class Vector {
private:
  double x, y;

public:
  Vector() {
    x = 0.0;
    y = 0.0;
  }

  Vector(double x, double y) {
    this->x = x;
    this->y = y;
  }

  Vector& add(const Vector& other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
  }

  Vector& substract(const Vector& other) {
    this->x -= other.x;
    this->y -= other.y;
    return *this;
  }

  Vector& multiply(double scalar) {
    this->x *= scalar;
    this->y *= scalar;
    return *this;
  }

  double dotProduct(const Vector& other) const {
    return this->x * other.x + this->y * other.y;
  }

  double getX() const { return x; }
  void setX(double x) { this->x = x; }

  double getY() const { return y; }
  void setY(double y) { this->y = y; }
};

int main() {
  Vector v1(1.0, 2.0);
  Vector v2(3.0, 4.0);

  Vector v3 = v1.add(v2);
  std::cout << v3 << std::endl;

  v3 = v1.substract(v2);
  std::cout << v3 << std::endl;

  v3 = v1.multiply(2.0);
  std::cout << v3 << std::endl;

  double scalarProduct = v1.dotProduct(v2);
  std::cout << "Scalar product: " << scalarProduct << std::endl;

  return 0;
}
