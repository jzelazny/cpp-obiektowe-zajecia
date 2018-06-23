#include "regularpolyhedron.h"
using namespace poly;
RegularPolyhedron::RegularPolyhedron(float a, int n, float h)
{
    this->a=a;
    this->n=n;
    this->h=h;
    pp = (n/4)*a*a*(1/std::tan(PI/n));
}

float RegularPolyhedron::getH(){
    return h;
}
float RegularPolyhedron::getPP(){
    return pp;
}
RegularPolyhedron::~RegularPolyhedron(){
}
