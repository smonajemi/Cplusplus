/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - DIY 6
*/
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <istream>
#include "Car.h"
namespace sdds
{
	class Racecar : public Car
	{
		double m_booster = 0.0;
	public:
		Racecar() {};
		Racecar(std::istream&);
		void display(std::ostream&) const;
		double topSpeed() const;
	};
}
#endif // !SDDS_RACECAR_H
