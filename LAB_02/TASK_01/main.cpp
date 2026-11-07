//H.SANDLEEN_L1S25BSCS0039
#include<iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
using namespace std;
int main()
{
	Circle c(2.5);
	Rectangle r(2.1, 5.0);
	cout << "Area of Circle: " << c.area() << endl;
	cout << "Area of rectangle: " << r.area() << endl;
}