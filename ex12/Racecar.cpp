/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - DIY 6
*/
#include <iostream>
#include <string>
#include "Racecar.h"
using namespace std;
namespace sdds
{
	Racecar::Racecar(istream& is) : Car(is)
	{
		string temp;
		getline(is, temp, ',');
		m_booster = stod(trim(temp));
	}
	void Racecar::display(ostream& os) const
	{
		Car::display(os); os << "*";
	}
	double Racecar::topSpeed() const
	{
		return Car::topSpeed() * (1 + m_booster);
	}
}