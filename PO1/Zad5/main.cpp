#include <iostream>
#include <cmath>
#include "point.h"
using namespace std;

float Distance(Point a, Point b) {
    return sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
}

int main()
{
    Point a = Point(10, 5);
    Point b = Point(0, 0);
    cout<<"A=("<<a.getX()<<","<<a.getY()<<")\nB=("<<b.getX()<<","<<b.getY()<<")\nDistance between A and B: " << Distance(a,b)<<endl;
    return 0;
}





