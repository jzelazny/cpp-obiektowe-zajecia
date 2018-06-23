#ifndef POINTSOPERATIONS_H
#define POINTSOPERATIONS_H

class Points;
struct Point;

class PointsOperations
{
private:
    static float distance(const Point&, const Point&);
public:
    static Point* closestToTheCenter(const Points&);
};

#endif // POINTSOPERATIONS_H
