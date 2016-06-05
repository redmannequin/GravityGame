#include "vector2D.h"

#include <iostream>
#include <cmath>
#define PI 3.14159265

Vector2D::Vector2D() {
    this->x = 0;
    this->y = 0;
}

Vector2D::~Vector2D() {}

// Subscript
float& Vector2D::operator[](int n) {
    if (n%2 == 0) return this->x;
    if (n%2 == 1) return this->y;
    return this->x;
}

// Dot-Product on two Vectors
float Vector2D::operator*(Vector2D& v) {
    float temp = 0;
    temp += this->x * v.x;
    temp += this->y * v.y;
    return temp;
}

// Binary
Vector2D Vector2D::operator+(Vector2D& v) {
    Vector2D temp = *this;
    temp += v;
    return temp;
}

Vector2D Vector2D::operator-(Vector2D& v) {
    Vector2D temp = *this;
    temp -= v;
    return temp;
}

Vector2D Vector2D::operator*(float n) {
    Vector2D temp = *this;
    temp *= n;
    return temp;
}

Vector2D Vector2D::operator/(float n) {
    Vector2D temp = *this;
    temp /= n;
    return temp;
}

// Assignment
void Vector2D::operator=(Vector2D v) {
    this->x = v.x;
    this->y = v.y;
}

void Vector2D::operator=(float *v) {
    this->x = v[0];
    this->y = v[1];
}

Vector2D& Vector2D::operator+=(Vector2D& v) {
    this->x += v.x;
    this->y += v.y;
    return *this;
}

Vector2D& Vector2D::operator-=(Vector2D& v) {
    this->x -= v[0];
    this->y -= v[1];
    return *this;
}

Vector2D& Vector2D::operator*=(float n) {
    this->x *= n;
    this->y *= n;
    return *this;
}

// rotate
Vector2D& Vector2D::operator/=(float n) {
    n *= PI/180.f;
    Vector2D v = *this;
    this->x = v.x*(std::cos(n)) - v.y*(std::sin(n));
    this->y = v.x*(std::sin(n)) + v.y*(std::cos(n));
    return *this;
}

