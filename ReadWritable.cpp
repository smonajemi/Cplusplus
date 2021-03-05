/*
File: MILESTONE 6

Name: SINA MONAJEMI
Email: smonajemi@myseneca.ca
Student Number: 021-324-124

Date: April 12, 2020 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "ReadWritable.h"

namespace sdds
{
	bool ReadWritable::isCsv() const
	{
		return m_flag;
	}

	void ReadWritable::setCsv(bool value)
	{
		m_flag = value;
	}

	std::ostream& operator<<(std::ostream& os, const ReadWritable& R)
	{
		return R.write(os);
	}

	std::istream& operator>>(std::istream& is, ReadWritable& R)
	{
		return R.read(is);
	}

}