/*
File: MILESTONE 6

Name: SINA MONAJEMI
Email: smonajemi@myseneca.ca
Student Number: 021-324-124

Date: April 12, 2020 */

#include "Vehicle.h"
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
namespace sdds

{
	class Car : public Vehicle
	{
		bool Carwash_flag = 0;
	public:
		Car() {};
		Car(const char* LicenceP, const char* make_model, bool Carwash_flag);

		Car(const Car&) = delete;
		Car& operator=(const Car&) = delete;

		std::ostream& write(std::ostream& os = std::cout) const;
		std::istream& read(std::istream& is = std::cin);

	};
	std::ostream& operator<<(std::ostream& os, const Car& c);
	std::istream& operator>>(std::istream& is, Car& c);
}
#endif // !SDDS_CAR_H
