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

// Dot-Product
float Vector2D::DotProduct(Vector2D& v1, Vector2D& v2) {
  float temp = 0;
  temp += v1.x * v2.x;
  temp += v1.y * v2.y;
  return temp;
}

// vector addition
void Vector2D::add(Vector2D& v) {*this += v;}

Vector2D Vector2D::operator+(Vector2D& v) {
 Vector2D temp = *this;
 temp += v;
 return temp;
}

Vector2D& Vector2D::operator+=(Vector2D& v) {
  this->x += v.x;
  this->y += v.y;
  return *this;
}

// vector subtraction
void Vector2D::sub(Vector2D& v) {*this += v;}

Vector2D Vector2D::operator-(Vector2D& v) {
  Vector2D temp = *this;
  temp -= v;
  return temp;
}

Vector2D& Vector2D::operator-=(Vector2D& v) {
  this->x -= v[0];
  this->y -= v[1];
  return *this;
}

// vector scalar multiplication
void Vector2D::mult(float n) {*this *= n;}

Vector2D Vector2D::operator*(float n) {
  Vector2D temp = *this;
  temp *= n;
  return temp;
}

Vector2D& Vector2D::operator*=(float n) {
  this->x *= n;
  this->y *= n;
  return *this;
}

// rotate vector
void Vector2D::rot(float n) {*this /= n;}

Vector2D Vector2D::operator/(float n) {
  Vector2D temp = *this;
  temp /= n;
  return temp;
}

Vector2D& Vector2D::operator/=(float n) {
  n *= PI/180.f;
  Vector2D v = *this;
  this->x = v.x*(std::cos(n)) - v.y*(std::sin(n));
  this->y = v.x*(std::sin(n)) + v.y*(std::cos(n));
  return *this;
}

// Assignment
void Vector2D::set(float x, float y) {
  this->x = x;
  this->y = y;
}

void Vector2D::operator=(Vector2D v) {
  this->x = v.x;
  this->y = v.y;
}

void Vector2D::operator=(float *v) {
  this->x = v[0];
  this->y = v[1];
}

