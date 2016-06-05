#ifndef POLYGON_H
#define POLYGON_H

#include "vector2D.h"

class Polygon {
  public:
    Polygon();
    ~Polygon();

    void setPolygon(int, Vector2D[]);
    void setPolygon(int n, int r); // creates polygon of n vertices

    void scl(float s); // scales polygon
    void rot(float r); // rotates polygon
    void tran(Vector2D& v); // translates polygon

    bool PnPoly(Vector2D&); // checks if point is in polygon

  private:
    int n; // number of vertices
    Vector2D * points; // vertices
};

#endif
