#include <iostream>
#include "regularprism.h"
#include "regularpyramid.h"
using namespace std;
using namespace poly;

int main()
{
    RegularPolyhedron *rp = new RegularPrism(3,4,5);
    cout << rp->volume() << endl;
    delete rp;
    rp=new RegularPyramid(3,4,5);
    cout << rp->volume() << endl;
    delete rp;
    return 0;
}
