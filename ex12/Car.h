/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - DIY 6
*/
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <string>
#include <istream>
#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle
	{
		std::string m_makemodel = "";
		std::string m_condition = "";
		double m_maxspeed = 0.0;

	protected:
		std::string trim(std::string&);

	public:
		Car() {};
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream&) const;

	};
}
#endif // !SDDS_CAR_H
