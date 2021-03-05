/*
File: MILESTONE 6

Name: SINA MONAJEMI
Email: smonajemi@myseneca.ca
Student Number: 021-324-124

Date: April 12, 2020 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
#include "Motorcycle.h"
#include "Utils.h"

namespace sdds
{
	Motorcycle::Motorcycle(const char* LicenceP, const char* make_model, bool Sidecar_flag) : Vehicle(LicenceP, make_model)
	{
		if (Vehicle::isEmpty())
			Motorcycle::isEmpty();
	}

	std::ostream& Motorcycle::write(std::ostream& os) const
	{
		
		if (Motorcycle::isEmpty())
			os << "Invalid Motorcycle Object" << endl;
		else
		{
			if (this->isCsv())
			{
				os << "M,";
				Vehicle::write(os) << Sidecar_flag << endl;
			}
			else
			{
				os << "Vehicle type: Motorcycle" << endl;
				Vehicle::write(os);
				if (Sidecar_flag)
					os << "With Sidecar" << endl;
			}
		}
		return os;			
	}

	std::istream& Motorcycle::read(std::istream& is)
	{
		if (this->isCsv())
		{
			Vehicle::read(is);
			if (setNum())
				Sidecar_flag = 1;
			else
			Sidecar_flag = 0;
		}
		else
		{
			cout << endl;
			cout << "Motorcycle information entry" << endl;
			Vehicle::read();
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			if (yes() == true)
				Sidecar_flag = true;
		}
		return is;
	}

	std::ostream& operator<<(std::ostream& os, const Motorcycle& m)
	{
		return m.write(os);
	}

	std::istream& operator>>(std::istream& is, Motorcycle& m)
	{
		return m.read(is);
	}

}