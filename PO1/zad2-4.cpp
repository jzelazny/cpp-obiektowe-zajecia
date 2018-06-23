#include <iostream>
#include <cmath>
using namespace std;
class Point {
private:
	float x, y;
public:
	Point(float x, float y);
	float getX();
	float getY();
	void move(Point p);
};
Point::Point(float x, float y) {
	this->x = x;
	this->y = y;
}
float Point::getX() {
	return x;
}
float Point::getY() {
	return y;
}
void Point::move(Point p) {
	x += p.getX();
	y += p.getY();
}

float Distance(Point p1, Point p2) {
	return sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
}



int main()
{
	Point p1 = Point(1, 10);
	Point p2 = Point(9, 10);
	cout << "p1=(" << p1.getX() << "," << p1.getY() << ")" << endl;
	cout << "\np2=(" << p2.getX() << "," << p2.getY() << ")" << endl;
	p1.move(p2);
	cout << "\nPrzesuniete p1=(" << p1.getX() << "," << p1.getY()<<")" << endl;
	cout << "\nOdleglosc |p1p2| = " << Distance(p1, p2) << endl;
		cin.get();
	return 0;
}




