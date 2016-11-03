#ifndef VECTOR_H
#define VECTOR_H

class Vector2D {
    public:
        Vector2D();

        // setters
        void set(float x, float y);
        void operator=(int);
        void operator=(float);
        void operator=(float[]);
        void operator=(Vector2D);

        // getters
        float Vector2D::getX();
        float Vector2D::getY();
        float* Vector2D::getXY();

        float& operator[](int);

        // adders
        void add(Vector2D&);
        Vector2D operator+(Vector2D&);
        Vector2D& operator+=(Vector2D&);

        // subtractors
        void sub(Vector2D&);
        Vector2D operator-(Vector2D&);
        Vector2D& operator-=(Vector2D&);

        // multipliers 
        void mult(float);
        Vector2D operator*(float);
        Vector2D& operator*=(float);

        // checks
        bool operator==(Vector2D&);
        bool operator!=(Vector2D&);

    private:
        float x;
        float y;

};

#endif