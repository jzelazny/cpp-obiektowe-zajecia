#ifndef REGULARPOLYHEDRON_H
#define REGULARPOLYHEDRON_H
#include <iostream>
#include <cmath>
#define PI 3.14
namespace poly{
class RegularPolyhedron
{
private:
    float a,pp,h;
    int n;
public:
    RegularPolyhedron(float a, int n, float h);
    virtual float volume()=0;
    virtual ~RegularPolyhedron();
protected:
    float getPP();
    float getH();

};
}
#endif // REGULARPOLYHEDRON_H
