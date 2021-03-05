/*
File: MILESTONE 6

Name: SINA MONAJEMI
Email: smonajemi@myseneca.ca
Student Number: 021-324-124

Date: April 12, 2020 */

#include "Vehicle.h"
#ifndef SDDS_MOTORCYCLE_H
#define SDDS_MOTORCYCLE_H
namespace sdds
{
	class Motorcycle : public Vehicle
	{
		bool Sidecar_flag = 0;

	public:
		Motorcycle() {};
		Motorcycle(const char* LicenceP, const char* make_model, bool Sidecar_flag);

		Motorcycle(const Motorcycle&) = delete;
		Motorcycle& operator=(const Motorcycle&) = delete;

		std::ostream& write(std::ostream& os = std::cout) const;
		std::istream& read(std::istream& is = std::cin);
	};
	std::ostream& operator<<(std::ostream& os, const Motorcycle& m);
	std::istream& operator>>(std::istream& is, Motorcycle& m);
}
#endif // !SDDS_MOTORCYCLE_H
