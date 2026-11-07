#include "Rectangle.h"
Rectangle::Rectangle(double l, double w) {
	length = l;
	width = w;
}
double Rectangle::area() {
	return (length * width);
}
