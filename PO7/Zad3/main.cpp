#include <iostream>
#include "triangle.h"
#include "rectangle.h"
using namespace std;

int main()
{
    Polygon *poly = new Triangle(5,5,5);
    cout<<"Trojkat: " << poly->circ()<<endl;
    poly = new Rectangle(2,3);
    cout << "Prostokat: " << poly->circ() << endl;
    delete poly;
    return 0;
}
