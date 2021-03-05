/*
	Sina Monajemi
	021-324-124
	smonajemi@myseneca.ca
	OOP244-NBB
	March 14, 2020
	Vehicle.h
*/

#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H

namespace sdds
{
	const int MIN_SPEED = 100;
	const int MAX_SPEED = 140;

	class Vehicle
	{
		int m_speed;
		int m_noOfSeats;
	protected:
		void set(int, int);
	

	public:

		Vehicle();
		Vehicle(int , int );

		void setEmpty();			
		bool finetune();
		std::ostream& display(std::ostream& os) const;
		std::istream& input(std::istream& in);
	};

	std::ostream& operator << (std::ostream& os, const Vehicle& v);
	std::istream& operator >> (std::istream& in , Vehicle& V);
}
#endif // !SDDS_VEHICLE_H
