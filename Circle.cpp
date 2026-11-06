#include "Circle.h"
Circle::Circle(double r) {
	radius = r;
}
double Circle::area() {
	return (3.14 * radius * radius);
}
