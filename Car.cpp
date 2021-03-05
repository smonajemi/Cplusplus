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
#include "Car.h"
#include "Utils.h"
namespace sdds
{
	Car::Car(const char* LicenceP, const char* make_model, bool Carwash_flag = 0) : Vehicle(LicenceP, make_model)
	{
		if (Vehicle::isEmpty())
			Car::isEmpty();
	}

	std::ostream& Car::write(std::ostream& os) const
	{
		if (Car::isEmpty())
			os << "Invalid Car Object" << endl;
		else
		{
			if (this->isCsv())
				os << "C,";
			else
				os << "Vehicle type: Car" << endl;
			Vehicle::write(os);
			if (Vehicle::isCsv())
				os << Carwash_flag << endl;
			else if (Carwash_flag == true)
			{
				os << "With Carwash" << endl;
			}
			else
			{
				os << "Without Carwash" << endl;
			}
		}
		return os;
	}

	std::istream& Car::read(std::istream& is)
	{
		if (this->isCsv())
		{
			Vehicle::read(is);
			if (setNum())
				Carwash_flag = 1;
			else
			Carwash_flag = 0;
		}
		else
		{
			cout << endl;
			cout << "Car information entry" << endl;
			Vehicle::read();
			cout << "Carwash while parked? (Y)es/(N)o: ";	
			if (yes() == true)
				Carwash_flag = true;
		}
		return is;
	}	

	std::ostream& operator<<(std::ostream& os, const Car& c)
	{
		return c.write(os);
	}

	std::istream& operator>>(std::istream& is, Car& c)
	{
		return c.read(is);
	}

}