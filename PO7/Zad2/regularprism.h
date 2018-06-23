#ifndef REGULARPRISM_H
#define REGULARPRISM_H
#include "regularpolyhedron.h"

namespace poly{
class RegularPrism:public RegularPolyhedron
{
public:
    RegularPrism(float a, float n, float h);
    virtual float volume() override;
    virtual ~RegularPrism();
};
}
#endif // REGULARPRISM_H
