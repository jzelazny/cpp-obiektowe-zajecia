#include <iostream>
#include <cmath>
#include "point.h"
#include "triangle.h"
using namespace std;

int main()
{
    Point p1 = Point(10, 20);
    Point p2 = Point(30, 40);
    Point p3 = Point(20,5);
    Triangle t1=Triangle(p1,p2,p3);
    cout<<"Perimeter: "<<t1.perimeter()<<"\nArea: "<<t1.area()<<endl;
        cin.get();
    return 0;
}





