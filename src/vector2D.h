#ifndef VECTOR_H
#define VECTOR_H

#include "defs.h"

class Vector2D {
  public:
    Vector2D();
    ~Vector2D();

    float x;
    float y;

    // Assignment
    void set(float, float);  

    void operator=(int);  
    void operator=(float); 
    void operator=(float[]);  
    void operator=(Vector2D); 

    // subscript
    float& operator[](int);

    // dot product
    float DotProduct(Vector2D&, Vector2D&);
 
    //vector addition
    void add(Vector2D&);
    Vector2D operator+(Vector2D&);
    Vector2D& operator+=(Vector2D&);

    // vector subtraction
    void sub(Vector2D&);
    Vector2D operator-(Vector2D&);
    Vector2D& operator-=(Vector2D&);
    
    // scalar multiplication
    void mult(float);
    Vector2D operator*(float);	 
    Vector2D& operator*=(float);
    
    // rotate by degree
    void rot(float);
    Vector2D operator/(float);
    Vector2D& operator/=(float); 

    // checks
    bool operator==(Vector2D&);
    bool operator!=(Vector2D&); 
};

#endif