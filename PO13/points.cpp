#include "points.h"
#include <exception>

using namespace std;

istream &operator>>(istream& is, Point& p) {
    is >> p.x; // >> p.y;
    is >> p.y;
    return is;
}

ostream& operator<<(ostream& os, const Point& p) {
    os << p.x << " " << p.y;
    return os;
}

Points::Points(int size)
{
    arr=new Point[size];
    this->size=size;
}

Points::~Points(){
    delete [] arr;
}

void Points::setAt(int index, const Point &a){
    arr[index]=a;
}

Point &Points::operator[](int index) {
    if(index<0 || index>=size)
        throw out_of_range("Index "+to_string(index)+" is out of range.");
    return arr[index];
}


std::ostream &operator<<(std::ostream& os, const Points& p){
    for(int i=0; i<p.size; i++){
        os << p.arr[i] << endl;
    }
    return os;
}
