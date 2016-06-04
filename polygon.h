#ifndef POLYGON_H
#define POLYGON_H

#include "vector2D.h"

class Polygon {
    public:
        Polygon();
        Polygon(int, Vector2D*);

        ~Polygon();

        void setPolygon(int, Vector2D*);

        void Scale(float);
        void Rotate(float);
        void Translate(Vector2D&);

        bool PnPoly(Vector2D&);

        void Print();
        void Clear();

    private:
        int n;
        Vector2D * points;
};

#endif // POLYGON_H
