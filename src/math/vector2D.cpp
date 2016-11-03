#include "./Vector2D.h"

Vector2D::Vector2D() {
    this->x = 0;
    this->y = 0;
}

// Setters
void Vector2D::set(float x, float y) {
    this->x = x;
    this->y = y;
}
void Vector2D::operator=(float n) {this->set(n, n);}
void Vector2D::operator=(float* v) {this->set(v[0], v[1]);}
void Vector2D::operator=(Vector2D v) {this->set(v[0], v[1]);}

// Getters

float& Vector2D::operator[](int n) {
    if (n%2 == 0) return this->x;
    return this->y;
}

float Vector2D::getX() {return this->x;}
float Vector2D::getY() {return this->y;}
float* Vector2D::getXY() {
    float temp[] = {this->x, this->y};
    return temp;
} 

// Adders
void Vector2D::add(Vector2D& v) {
    this->x += v[0];
    this->y += v[1];
}

Vector2D Vector2D::operator+(Vector2D& v) {
    Vector2D temp = *this;
    temp += v;
    return temp;
}

Vector2D& Vector2D::operator+=(Vector2D& v) {
    this->add(v);
    return *this;
}

// Multipliers 
void Vector2D::mult(float n) {
    this->x *= n;
    this->y *= n;
}

Vector2D Vector2D::operator*(float n) {
    Vector2D temp = *this;
    temp.mult(n);
    return temp;
}

Vector2D& Vector2D::operator*=(float n) {
    this->mult(n);
    return *this;
}

// Subtractors
void Vector2D::sub(Vector2D& v) {this->add(v*(-1));}
Vector2D Vector2D::operator-(Vector2D& v) {return *this+(v*(-1));}
Vector2D& Vector2D::operator-=(Vector2D& v) {return *this+=(v*(-1));}

// Checks
bool Vector2D::operator==(Vector2D& v) {
    if (this->x == v[0] && this->y == v[1]) return true;
    return false;
}
bool Vector2D::operator!=(Vector2D& v) {return !(*this==v);}