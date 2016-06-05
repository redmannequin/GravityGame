#include "polygon.h"

#include <iostream>
#include <cmath>
#define PI 3.14159265

Polygon::Polygon() {
  this->n=0;
  this->points = NULL;
}

Polygon::~Polygon() {delete[] points;}

void Polygon::setPolygon(int n, Vector2D points[]) {
  this->n = n;
  this->points = new Vector2D[n];
  for (int i=0; i < n ; ++i) {
    this->points[i] = points[i];
  }
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

// translates polygon
void Polygon::tran(Vector2D & disp) {
  for (int i=0; i < this->n; ++i) 
    points[i] += disp;
}

// scales polygon
void Polygon::scl(float s) {
  for (int i=0; i < this->n; ++i) 
    points[i] *= s;
}

// rotates polygon
void Polygon::rot(float r) {
  for (int i=0; i < this->n; ++i) 
    points[i] /= r;
}

// checks if point is in polygon
bool Polygon::PnPoly(Vector2D & point) {
  int  j = n-1;
  bool c = 0;
  Vector2D vi, vj;
  for (int i=0; i < n; j = i++) {
    vi = points[i];
    vj = points[j];
    if ((vi.y >= point.y) !=  (vj.y >= point.y)) {
      if (point.x <= (vj.x-vi.x)*(point.y-vi.y)/(vj.y-vi.y)+vi.x) {
        c = !c;
      }
    }
  }
  return c;
}

