/*
	Sina Monajemi
	021-324-124
	smonajemi@myseneca.ca
	OOP244-NBB
	March 14, 2020
	Car.cpp
*/

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

#include <iostream>
#include <cstring>
#include "Vehicle.h"
#include "Car.h"

namespace sdds
{
	void Car::set(char carType[], int regYear)
	{
		(carType[0] != '\0' && regYear >= MIN_YEAR);
	}
	Car::Car()
	{
		setEmpty();
	}

	Car::Car(const char* carType, int regYear, int carSpeed, int carSeat) : Vehicle(carSpeed ,carSeat)
	{
		setEmpty();
		if (carType[0] != '\0' && regYear >= MIN_YEAR)
		{
			strcpy(m_carType, carType);
			m_regYear = regYear;
		}
		else {setEmpty();}
	}

	void Car::finetune()
	{
		if (m_regYear < MIN_YEAR)
		{
			cout << "Car cannot be tuned and has to be scraped" << endl;
		}
		else
		{
			Vehicle::finetune();
			cout << "This car is finely tuned to default speed" << endl;
		}

	}

	void Car::setEmpty()
	{
		m_carType[0] = '\0';
		m_regYear = 0;
	}

	ostream& Car::display(ostream& os = cout) const
	{
		if (m_carType[0] == '\0' || m_regYear < MIN_YEAR)
		{
			os << "Car is not initiated yet" << endl;
		}
		else
		{
			os.width(20);
			os.setf(ios::left);
			os << m_carType << m_regYear;
			Vehicle::display(os);
			os.unsetf(ios::left);
		}
		return os;
	}

	istream& Car::input(istream& in = cin)
	{
			cout << "Enter the car type: ";
				in >> m_carType;
			cout << "Enter the car registration year: ";
				in >> m_regYear;
				set(m_carType, m_regYear);
			Vehicle::input(in);
			return in;
	}
	ostream& operator<<(ostream& os, const Car& c)
	{
		c.display(os);
		return os;		
	}
	istream& operator>>(istream& in, Car& c)
	{
		c.input(in);
		return in;
	}
}