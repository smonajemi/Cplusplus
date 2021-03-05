/*
File Name: Lab_8 - OOP244-NBB
Name: Sina Monajemi
Student Number: 021-324-124
Email: smonajemi@myseneca.ca

Date: March 27, 2020
Doctor.h
----------------------------------------------------
*/
#include "Employee.h"

#ifndef SDDS_DOCTOR_H
#define SDDS_DOCTOR_H

namespace sdds
{
	const int MIN_W_HOURS = 6;
	const int MAX_CHAR = 20;
	class Doctor : public Employee
	{
		char m_type[MAX_CHAR + 1]{};
		double m_salary = 0.0;
		int m_whours = 0;
		bool m_specialist = false;

	protected:
		bool isEmpty() const;
		void setEmptyState();

	public:
		Doctor();
		Doctor(const char*, double, int, bool specialist = false);
		//~Doctor();
		
		void setSalary(double);
		void bonus();
		bool workHours();

		std::ostream& display(std::ostream& os = std::cout) const;
	};
	std::ostream& operator<<(std::ostream& os, const Doctor& rop);
}

#endif // !SDDS_DOCTOR_H
