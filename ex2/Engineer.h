/*
File Name: Lab_8 - OOP244-NBB
Name: Sina Monajemi
Student Number: 021-324-124
Email: smonajemi@myseneca.ca

Date: March 27, 2020
Engineer.h
----------------------------------------------------
*/
#include "Employee.h"

#ifndef SDDS_ENGINEER_H
#define SDDS_ENGINEER_H

namespace sdds
{
	const int MIN_HOURS = 5;
	const int MAX_LEVEL = 4;

	class Engineer : public Employee
	{
		double m_salary = 0.0;
		int m_ewhours = 0;
		int m_level = 0;

	protected:
		bool isEmpty() const;
		void setEmptyState();

	public:
		Engineer();
		Engineer(double salary, int hours, int level);
	//	~Engineer();

		void setSalary(double);
		void bonus();
		bool workHours();


		std::ostream& display(std::ostream& os = std::cout) const;
	};

	std::ostream& operator<<(std::ostream& os, const Engineer& rop);
}

#endif // !SDDS_ENGINEER_H
