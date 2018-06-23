#include "regularpyramid.h"
using namespace poly;
RegularPyramid::RegularPyramid(float a, int n, float h):RegularPolyhedron(a,n,h)
{
}

float RegularPyramid::volume(){
    return (getPP()/3)*getH();
}
RegularPyramid::~RegularPyramid(){
    std::cout << "Usuwam RegularPyramid" << std::endl;
}
