#pragma once
#include "Employee.h"
class FullTimeEmployee: public Employee {
private:
	double fixedSalary;
public:
	FullTimeEmployee(double fs);
	double calculateSalary() override;
};

