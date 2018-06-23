#include "regularprism.h"
using namespace poly;
RegularPrism::RegularPrism(float a, float n, float h):RegularPolyhedron(a,n,h){}

float RegularPrism::volume(){
    return getH()*getPP();
}
RegularPrism::~RegularPrism(){
    std::cout<<"Usuwam RegularPrism" << std::endl;
}
