/*
File Name: Lab_8 - OOP244-NBB
Name: Sina Monajemi
Student Number: 021-324-124
Email: smonajemi@myseneca.ca

Date: March 27, 2020
Employee.h
----------------------------------------------------
*/

#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H

namespace sdds
{
	class Employee
	{
	public:

		virtual void setSalary(double) = 0;
		virtual void bonus() = 0;
		virtual bool workHours() = 0;
		virtual std::ostream& display(std::ostream& os = std::cout) const = 0;
		virtual ~Employee() {};
	};
	//std::ostream& operator<<(std::ostream& os, const Shape& rop) {};
}

#endif // !SDDS_EMPLOYEE_H
