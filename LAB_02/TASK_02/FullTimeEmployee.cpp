#include "FullTimeEmployee.h"
FullTimeEmployee::FullTimeEmployee(double fs) {
	fixedSalary = fs;
}
double FullTimeEmployee::calculateSalary() {
	return fixedSalary;
}
