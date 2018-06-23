#ifndef REGULARPYRAMID_H
#define REGULARPYRAMID_H
#include "regularpolyhedron.h"

namespace poly{
class RegularPyramid:public RegularPolyhedron
{
public:
    RegularPyramid(float a, int n, float h);
    virtual float volume() override;
    virtual ~RegularPyramid();
};
}

#endif // REGULARPYRAMID_H
