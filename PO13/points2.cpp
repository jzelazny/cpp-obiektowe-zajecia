#include "pointsoperations.h"
#include <cmath>
#include "points.h"
#include "multiplepointsexceptions.h"

float PointsOperations::distance(const Point &p1, const Point &p2)
{
    return hypot(p2.x - p1.x, p2.y - p1.y);
}

Point* PointsOperations::closestToTheCenter(const Points &points)
{
    Point avg = {0, 0};
    for (int i = 0; i < points.size; i++) {
        avg = { avg.x + points.arr[i].x, avg.y + points.arr[i].y};
    }

    avg = { avg.x / points.size, avg.y / points.size };

    std::vector<Point*> closest;
    closest.push_back(points.arr);
    float d = distance(avg, *(closest[0]));

    for (int i = 1; i < points.size; i++) {
        float dd = distance(avg, points.arr[i]);
        if(dd == d) {
            closest.push_back(&points.arr[i]);
        }
        if(dd < d) {
            closest.clear();
            closest.push_back(&points.arr[i]);
            d = dd;
        }
    }
    if(closest.size() == 1)
        return closest[0];
    throw MultiplePointsException(closest);
}
