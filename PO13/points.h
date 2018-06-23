#ifndef POINTS_H
#define POINTS_H

#include <iostream>
#include "pointsoperations.h"

struct Point {
    float x, y;
};

std::istream &operator>>(std::istream& is, Point& p);
std::ostream &operator<<(std::ostream& os, const Point& p);

class Points
{
    Point *arr;
    int size;
public:
    Points(int size);
    ~Points();
    void setAt(int index, const Point &a);
    Point &operator[](int index);


    friend std::ostream &operator<<(std::ostream& os, const Points& arr);
    //friend class PointsOperations;
    friend Point* PointsOperations::closestToTheCenter(const Points &points);


};

std::ostream &operator<<(std::ostream& os, const Points& p);

#endif // POINTS_H
