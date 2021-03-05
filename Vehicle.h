/*
File: MILESTONE 6

Name: SINA MONAJEMI
Email: smonajemi@myseneca.ca
Student Number: 021-324-124

Date: April 12, 2020 */

#include "ReadWritable.h"
#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H

namespace sdds
{
	const int MAX_LICENCEPLATE = 8;
	class Vehicle : public ReadWritable
	{
		char m_licence[MAX_LICENCEPLATE + 1]{};
		char* m_make_model = nullptr;
		unsigned int m_spotnum = 0;
		bool validation = false;
		
	protected:
		void setEmpty();
		bool isEmpty() const;
		char* getMakeModel() const;
		char getLicencePlate() const;
		void setMakeModel(const char*);
		void setLicence(const char*);
		void setCapital(char*); // set to upper case
		void clearMemory();

	public:
		Vehicle() {};
		Vehicle(const char*, const char*);
		~Vehicle();

		Vehicle(const Vehicle&) = delete;
		Vehicle& operator=(const Vehicle& src) = delete;

		int getParkingSpot() const;
		void setParkingSpot(int num = 0);
		bool setNum();

		std::ostream& write(std::ostream& os = std::cout) const;
		std::istream& read(std::istream& is = std::cin);
		bool operator==(const char*) const;
		bool operator==(const Vehicle&) const;
	};

	std::ostream& operator<<(std::ostream& os, const Vehicle& v);
	std::istream& operator>>(std::istream& is, Vehicle& v);

}
#endif // !SDDS_VEHICLE_H
