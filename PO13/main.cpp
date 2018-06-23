#include "points.h"
#include "pointsoperations.h"
#include "multiplepointsexceptions.h"

using namespace std;

int main() {
    Points p(2);
//    p.setAt(0, {1,2});
//    p.setAt(1, {0,3});
//    p.setAt(2, {4,5});
//    p.setAt(3,{6,7});
//    cout << p << endl;
    p.setAt(0, {1,2});
    p.setAt(1, {2,1});

    try {
        Point* closest = PointsOperations::closestToTheCenter(p);
        cout << *closest << endl;
    }
    catch(MultiplePointsException &e)
    {
        cerr << e.what();
//        for(Point *p : e.v)
//            cout << *p << endl;
    }


    return 0;
}
