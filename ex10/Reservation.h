/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - DIY4
*/
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <iostream>
#include <string>

namespace sdds
{
	class Reservation
	{
		std::string m_rezId = "";
		std::string m_rezName = "";
		std::string m_rezEmail = "";
		size_t m_numofParty = 0;
		size_t m_day = 0;
		size_t m_time = 0;

		std::string trim(std::string& str);
	public:
		// Constructors
		Reservation() {};
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& res); //Friend Helper Insertion Operator
	};

}
#endif // !SDDS_RESERVATION_H
