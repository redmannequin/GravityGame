#ifndef VECTOR_H
#define VECTOR_H

class Vector2D
{
    public:
        Vector2D();
        ~Vector2D();

        float x;
        float y;

        void operator=(float*);
        void operator=(Vector2D);
        float& operator[](int);

        float operator*(Vector2D&);

        Vector2D operator+(Vector2D&);
        Vector2D operator-(Vector2D&);
        Vector2D operator*(float);
        Vector2D operator/(float);

        Vector2D& operator+=(Vector2D&);
        Vector2D& operator-=(Vector2D&);
        Vector2D& operator*=(float);
        Vector2D& operator/=(float);

};

#endif // VECTOR_H
