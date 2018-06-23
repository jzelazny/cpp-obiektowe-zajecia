#include "triangle.h"
#include <cmath>

Triangle::Triangle(Point a, Point b, Point c){
    this->a=a;
    this->b=b;
    this->c=c;
}
float Triangle::Distance(Point a, Point b){
    return sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
}
float Triangle::perimeter(){
    return Distance(a,b)+Distance(b,c)+Distance(c,a);
}
float Triangle::area(){
    float p=perimeter()/2;
    return sqrt(p*(p-Distance(a,b))*(p-Distance(b,c))*(p-Distance(c,a)));
}

