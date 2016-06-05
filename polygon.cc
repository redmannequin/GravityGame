#include "polygon.h"

#include <iostream>
#include <cmath>
#define PI 3.14159265

Polygon::Polygon() {
    this->n=0;
    this->points = NULL;
}

Polygon::Polygon(int n, Vector2D* points) {
    setPolygon(n, points);
}

void Polygon::setPolygon(int n, Vector2D * points) {
    this->n = n;
    this->points = new Vector2D[n];
    for (int i = 0; i < n ; ++i) {
        this->points[i] = points[i];
    }
}

Polygon::~Polygon(){}

void Polygon::Clear() {
    delete[] points;
}

void Polygon::Translate(Vector2D & disp) {
    for (int i=0; i < this->n; ++i) points[i] += disp;
}

void Polygon::Scale(float s) {
    for (int i=0; i < this->n; ++i) points[i] *= s;
}

void Polygon::Rotate(float r) {
    for (int i=0; i < this->n; ++i) points[i] /= r;
}

bool Polygon::PnPoly(Vector2D & point) {
    int  j = n-1;
    bool c = 0;
    for (int i = 0; i < n; j = i++) {
        Vector2D vi = points[i];
        Vector2D vj = points[j];
        if ((vi.y >= point.y) !=  (vj.y >= point.y)) {
            if (point.x <= (vj.x - vi.x) * (point.y - vi.y) / (vj.y - vi.y) + vi.x ) {
                c = !c;
            }
        }
    }
    return c;
}

void Polygon::Print() {
    std::cout << "points: " << n << std::endl;
    for (int i = 0; i < n; ++i)
        std::cout << "p" << i << ": {" << points[i][0] << ", " << points[i][1] << "}" << std::endl;
}
