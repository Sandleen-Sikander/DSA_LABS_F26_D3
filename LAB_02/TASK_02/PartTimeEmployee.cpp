#include "PartTimeEmployee.h"
PartTimeEmployee::PartTimeEmployee(double hw, double hr) {
	hours_worked = hw;
	hourly_rate = hr;
}
double PartTimeEmployee::calculateSalary() {
	return (hours_worked * hourly_rate);
}
