#ifndef VECTOR_H
#define VECTOR_H

class Vector {
    public:
        Vector();
        ~Vector();

        float x;
        float y;

        void operator=(float*);
        void operator=(Vector);
        float& operator[](int);

        float operator*(Vector&);

        Vector operator+(Vector&);
        Vector operator-(Vector&);
        Vector operator*(float);

        Vector& operator+=(Vector&);
        Vector& operator-=(Vector&);
        Vector& operator*=(float);

};

#endif // VECTOR_H
