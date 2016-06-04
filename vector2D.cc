#include "vector2D.h"

Vector::Vector() {
    this->x = 0;
    this->y = 0;
}

Vector::~Vector() {}

// Subscript
float& Vector::operator[](int n) {
    if (n == 0) return this->x;
    if (n == 1) return this->y;
    return this->x;
}

// Dot-Product on two Vectors
float Vector::operator*(Vector& v) {
    float temp;
    temp += this->x * v[0];
    temp += this->y * v[1];
    return temp;
}

// Binary
Vector Vector::operator+(Vector& v) {
    Vector temp = *this;
    temp += v;
    return temp;
}

Vector Vector::operator-(Vector& v) {
    Vector temp = *this;
    temp -= v;
    return temp;
}

Vector Vector::operator*(float n) {
    Vector temp = *this;
    temp *= n;
    return temp;
}

// Assignment
void Vector::operator=(Vector v) {
    this->x = v[0];
    this->y = v[1];
}

void Vector::operator=(float *v) {
    this->x = v[0];
    this->y = v[1];
}

Vector& Vector::operator+=(Vector& v) {
    this->x += v[0];
    this->y += v[1];
    return *this;
}

Vector& Vector::operator-=(Vector& v) {
    this->x -= v[0];
    this->y -= v[1];
    return *this;
}

Vector& Vector::operator*=(float n) {
    this->x *= n;
    this->y *= n;
    return *this;
}
