#include <iostream>

using namespace std;
class Point {
private:
	float x, y;
public:
	float getX();
	float getY();
	void move(float x, float y);
	void setX(float a);
	void setY(float b);
};
float Point::getX() {
	return x;
}
float Point::getY() {
	return y;
}
void Point::setX(float newValue) {
	this->x = newValue;
}
void Point::setY(float newValue) {
	this->y = newValue;
}
void Point::move(float a, float b) {
	x += a;
	y += b;
}


int main()
{
	Point p1 = Point();
	p1.setX(5);
	p1.setY(10);
	cout << "p1=(" << p1.getX() << "," << p1.getY() << ")" << endl;
	p1.move(1, 1);
	cout <<"---Przesuniecie---\n"<< "p1=(" << p1.getX() << "," << p1.getY() << ")" << endl;
//	cin.get();
    return 0;
}


