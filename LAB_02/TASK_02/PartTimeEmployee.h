#pragma once
#include "Employee.h"
class PartTimeEmployee : public Employee{
private:
	double hours_worked;
	double hourly_rate;
public:
	PartTimeEmployee(double hw, double hr);
	double calculateSalary() override;
};

