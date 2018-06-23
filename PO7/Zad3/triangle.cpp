#include "triangle.h"

Triangle::Triangle(double a, double b, double c)
{
    this->a=a;
    this->b=b;
    this->c=c;
}
double Triangle::circ(){
    return a+b+c;
}
