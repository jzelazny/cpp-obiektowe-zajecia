#include <iostream>
#include <vector>
#include <algorithm>
#include "point.h"
using namespace std;

vector<Point> getVector(const vector<Point> &vec, Point topLeftCorner, Point bottomRightCorner){
    vector<Point> rectangle;
    for(Point p:vec){
        if(p.getX()>=topLeftCorner.getX() && p.getX()<=bottomRightCorner.getX())
            if(p.getY()<=topLeftCorner.getY() && p.getY()>=bottomRightCorner.getY())
                rectangle.push_back(p);
    }
    return rectangle;
}
int main()
{
    vector<Point> vec;
    Point points[2];
    points[0] = Point(20,80);
    points[1] = Point(85,10);
    cout << "Original vector: " << endl;
    for(int i=0;i<15;i++){
        vec.push_back(Point(rand()%100,rand()%100));
        cout << vec[i].getX() << " " << vec[i].getY() << endl;
    }
    cout << "Rectangle from "<<points[0].getX()<<","<<points[0].getY()
         <<" to " <<points[1].getX()<<","<<points[1].getY()<<" : " << endl;
    vector<Point> rectangle = getVector(vec,points[0],points[1]);
    for(Point p:rectangle)
        cout << p.getX() << " " << p.getY() << endl;

}
