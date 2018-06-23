#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "polygon.h"

class Triangle:public Polygon
{
private:
    double a, b, c;
public:
    Triangle(double a, double b, double c);
    virtual double circ() override;
};

#endif // TRIANGLE_H
