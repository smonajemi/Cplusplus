/*
File Name: Lab_8 - OOP244-NBB
Name: Sina Monajemi
Student Number: 021-324-124
Email: smonajemi@myseneca.ca

Date: March 27, 2020
Doctor.cpp
----------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <cstring>
#include "Employee.h"
#include "Doctor.h"

namespace sdds
{
	bool Doctor::isEmpty() const
	{
		return (m_type[0] == '\0' && m_salary == 0 && m_whours == 0);
	}

	void Doctor::setEmptyState()
	{
		m_type[0] = '\0';
		m_salary = 0.0;
		m_whours = 0;
		m_specialist = false;
	}

	Doctor::Doctor() {}

	Doctor::Doctor(const char* type, double salary, int wh, bool specialist)
	{
		if (salary <= 0 || wh <= 0)	{setEmptyState();}
		else
		{
			strncpy(m_type, type, MAX_CHAR);
			m_type[MAX_CHAR] = '\0';

			m_whours = wh;
			m_specialist = specialist;
			setSalary(salary);
		}
	}
	
	void Doctor::setSalary(double salary)
	{
		(m_specialist == true) ? (m_salary = (salary += 2000)) : m_salary = salary;
	}
	void Doctor::bonus()
	{
		(m_whours > MIN_W_HOURS) ? (m_salary += (m_salary * 0.10)) : (m_salary += (m_salary * 0.05));
	}
	
	bool Doctor::workHours()
	{
		return m_whours <= MIN_W_HOURS;
	}
	std::ostream& Doctor::display(std::ostream& os) const
	{
		if (isEmpty())
		{
			os << "Doctor is not initiated yet" << endl;
		}
		else
		{
			os << "Doctor details" << endl;
			os << "Doctor Type: " << m_type << endl;
			os.setf(ios::fixed);
			os.precision(2);
			os << "Salary: " << m_salary << endl; os.unsetf(ios::fixed);
			os << "Working hours: " << m_whours << endl;
		}

		return os;
	}
	ostream& operator<<(ostream& os, const Doctor& rop)
	{
		rop.display(os);
		return os;
	}
}
