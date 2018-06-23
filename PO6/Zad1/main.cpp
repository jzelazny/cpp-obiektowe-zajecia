#include <iostream>
#include <vector>
#include <algorithm>
#include "point.h"
using namespace std;

bool compX(Point p1, Point p2){
    return (p1.getX()<p2.getX());
}
bool compY(Point p1, Point p2){
    return (p1.getY()<p2.getY());
}

int main()
{
    vector<Point> vec;
    cout << "Original vector: " << endl;
    for(int i=0;i<5;i++){
        vec.push_back(Point(rand()%100,rand()%100));
        cout << vec[i].getX() << " " << vec[i].getY() << endl;
    }

    cout <<"Sorted by X: " <<  endl;
    sort(vec.begin(),vec.end(),compX);
    for(Point p:vec)
        cout << p.getX() << " " << p.getY() << endl;

    cout <<"Sorted by Y: " <<  endl;
    sort(vec.begin(),vec.end(),compY);
    for(Point p:vec)
        cout << p.getX() << " " << p.getY() << endl;
}
