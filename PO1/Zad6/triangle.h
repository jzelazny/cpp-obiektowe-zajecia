#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "point.h"

class Triangle
{
    private:
        Point a,b,c;
    public:
        Triangle(Point a, Point b, Point c);
        float Distance(Point a, Point b);
        float perimeter();
        float area();
};

#endif // TRIANGLE_H
