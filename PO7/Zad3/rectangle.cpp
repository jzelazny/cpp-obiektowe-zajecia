#include "rectangle.h"

Rectangle::Rectangle(double a, double b)
{
    this->a=a;
    this->b=b;
}
double Rectangle::circ(){
    return a+a+b+b;
}
