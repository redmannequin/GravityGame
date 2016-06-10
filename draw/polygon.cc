#include "polygon.h"

Polygon::Polygon() {
  this->n=0;
  this->points = 0;
}

Polygon::~Polygon() {this->clear();}

void Polygon::setPolygon(Vector2D points[]) {
  *this = points;  
}

void Polygon::clear() {
  this->n = 0;
  if (this->points != 0) delete[] this->points;
}

// creates polygon of n vertices with equal length sides 
void Polygon::setPolygon(int n, int r) {
  this->n = n;
  this->points = new Vector2D[n];
  float angle = 0;
  float da = 360/n;
  for (int i=0; i < n; ++i) {
    this->points[i].y = r;
    this->points[i] /= angle;
    angle += da;
  }
}

void Polygon::operator=(Vector2D points[]) {
  if (this->n >= 1) this->clear();
  this->n = (sizeof(*points));
  this->points = new Vector2D[this->n];
  for (int i=0; i < n ; ++i) this->points[i] = points[i];  
}

void Polygon::operator=(Polygon& poly) {
  *this = poly.points;
}

// translates polygon
void Polygon::tran(Vector2D& disp) {
  for (int i=0; i < this->n; ++i) 
    this->points[i] += disp;
}

Polygon Polygon::operator+(Vector2D& v) {
  Polygon temp = *this;
  temp += v;
  return temp;
}

Polygon& Polygon::operator+=(Vector2D& v) {
  for (int i=0; i < this->n; ++i) 
    this->points[i] += v;
  return *this;
}

Polygon Polygon::operator-(Vector2D& v) {
  Polygon temp = *this;
  temp -= v;
  return temp;
}

Polygon& Polygon::operator-=(Vector2D& v) {
  for (int i=0; i < this->n; ++i)
    this->points[i] -= v;
  return *this;
}

// scales polygon
void Polygon::scl(float s) {
  for (int i=0; i < this->n; ++i) 
    this->points[i] *= s;
}

Polygon Polygon::operator*(float) {}
Polygon& Polygon::operator*=(float) {}

// rotates polygon
void Polygon::rot(float r) {
  for (int i=0; i < this->n; ++i) 
    this->points[i] /= r;
}

Polygon Polygon::operator/(float) {}
Polygon& Polygon::operator/=(float) {}

// checks if point is in polygon
bool Polygon::PnPoly(Vector2D & point) {
  int  j = n-1;
  bool c = 0;
  Vector2D vi, vj;
  for (int i=0; i < this->n; j = i++) {
    vi = this->points[i];
    vj = this->points[j];
    if ((vi.y > point.y) !=  (vj.y > point.y)) {
      if (point.x < (vj.x-vi.x)*(point.y-vi.y)/(vj.y-vi.y)+vi.x) {
        c = !c;
      }
    }
  }
  return c;
}

