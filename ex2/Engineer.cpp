/*
File Name: Lab_8 - OOP244-NBB
Name: Sina Monajemi
Student Number: 021-324-124
Email: smonajemi@myseneca.ca

Date: March 27, 2020
Engineer.cpp
----------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <cstring>
#include "Employee.h"
#include "Engineer.h"

namespace sdds
{
	bool Engineer::isEmpty() const
	{
		return (m_salary == 0 && m_level == 0 && m_ewhours == 0);
	}

	void Engineer::setEmptyState()
	{
		m_salary = 0.0;
		m_ewhours = 0;
		m_level = 0;
	}

	Engineer::Engineer() {}

	Engineer::Engineer(double salary, int hours, int level)
	{
		if (salary <= 0 && hours <= 0)
		{
			setEmptyState();
		}
		else
		{
			m_level = level;
			m_ewhours = hours;
			setSalary(salary);
		}
	}

	void Engineer::setSalary(double salary)
	{
		(m_level == MAX_LEVEL) ? (m_salary = salary + 3000) : (m_salary = salary);
	}

	void Engineer::bonus()
	{
		(m_ewhours > MIN_HOURS) ? (m_salary += (m_salary * 0.10)) : (m_salary += (m_salary * 0.05));
	}

	bool Engineer::workHours()
	{
		return m_ewhours <= MIN_HOURS;
	}

	std::ostream& Engineer::display(std::ostream& os) const
	{
		if (isEmpty())
		{
			os << "Engineer is not initiated yet" << endl;
		}
		else
		{
			os << "Engineer details" << endl;
			os << "level: " << m_level << endl;
			os.setf(ios::fixed);
			os.precision(2);
			os << "Salary: " << m_salary << endl; os.unsetf(ios::fixed);
			os << "Working hours: " << m_ewhours << endl;
		}

		return os;
	}

	ostream& operator<<(ostream& os, const Engineer& rop)
	{
		rop.display(os);
		return os;
	}

}