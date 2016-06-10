#ifndef POLYGON_H
#define POLYGON_H

#include "./draw.h"
#include "../vector2D.h"
#include "../defs.h"
//#include "../collections/list.h"

class Polygon : public Draw {
  public:
    Polygon();
    ~Polygon();

    void setPolygon(Vector2D[]);
    void setPolygon(int n, int r); // creates polygon of n vertices

    void clear();

    void operator=(Vector2D[]);
    void operator=(Polygon&);

    // scales polygon
    void scl(float s);
    Polygon operator*(float);
    Polygon& operator*=(float);

    // rotates polygon
    void rot(float r); 
    Polygon operator/(float);
    Polygon& operator/=(float);

    // translates polygon
    void tran(Vector2D& v); 
    Polygon operator+(Vector2D&);
    Polygon operator-(Vector2D&);
    Polygon& operator+=(Vector2D&);
    Polygon& operator-=(Vector2D&);

    bool PnPoly(Vector2D&); // checks if point is in polygon

  private:
    int n; // number of vertices
    Vector2D * points; // vertices
};

#endif