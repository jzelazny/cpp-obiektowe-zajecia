#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "polygon.h"

class Rectangle:public Polygon
{
private:
    double a, b;
public:
    Rectangle(double a, double b);
    virtual double circ() override;
};

#endif // RECTANGLE_H
