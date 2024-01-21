#include <iostream>

class Vector {
private:
  double x, y;

public:
  Vector() {}

  Vector(double x, double y) {
    this->x = x;
    this->y = y;
  }

  Vector& operator=(const Vector& other) {
    this->x = other.x;
    this->y = other.y;
    return *this;
  }

  Vector& operator+=(const Vector& other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
  }

  Vector& operator-=(const Vector& other) {
    this->x -= other.x;
    this->y -= other.y;
    return *this;
  }

  Vector operator+(const Vector& other) const {
    return Vector(this->x + other.x, this->y + other.y);
  }

  Vector operator-(const Vector& other) const {
    return Vector(this->x - other.x, this->y - other.y);
  }

  Vector operator*(double scalar) const {
    return Vector(this->x * scalar, this->y * scalar);
  }

  double operator*(const Vector& other) const {
    return this->x * other.x + this->y * other.y;
  }

  double getX() const { return x; }

  void setX(double x) { this->x = x; }

  double getY() const { return y; }

  void setY(double y) { this->y = y; }

  friend std::ostream& operator<<(std::ostream& out, const Vector& vector) {
    out << "(" << vector.x << ", " << vector.y << ")";
    return out;
  }

  friend std::istream& operator>>(std::istream& in, Vector& vector) {
    in >> vector.x >> vector.y;
    return in;
  }
};

int main() {
  Vector v1(1.0, 2.0);
  Vector v2(3.0, 4.0);

  std::cout << v1 << std::endl;
  std::cout << v2 << std::endl;

  Vector v3 = v1 + v2;
  std::cout << v3 << std::endl;

  v3 = v1 - v2;
  std::cout << v3 << std::endl;

  v3 = v1 * 2.0;
  std::cout << v3 << std::endl;

  double scalarProduct = v1 * v2;
  std::cout << "Scalar product: " << scalarProduct << std::endl;

  return 0;
}
