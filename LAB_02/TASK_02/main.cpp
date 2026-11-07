//H.SANDLEEN_L1S25BSCS0039
#include<iostream>
#include "Employee.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"
using namespace std;
int main()
{
	FullTimeEmployee fEmployee(50000);
	PartTimeEmployee pEmployee(18, 2000);
	cout << "Full-Time Employee Salary: " << fEmployee.calculateSalary() << " Pkr" << endl;
	cout << "Part-Time Employee Salary: " << pEmployee.calculateSalary() << " Pkr" << endl;
}