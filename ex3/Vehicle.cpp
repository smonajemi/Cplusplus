/*
	Sina Monajemi
	021-324-124
	smonajemi@myseneca.ca
	OOP244-NBB
	March 14, 2020
	Vehicle.cpp
*/

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

#include <iostream>
#include <cstring>
#include "Vehicle.h"

namespace sdds
{
	void Vehicle::set(int _spd, int _seatnum)
	{
		 (_spd >= MIN_SPEED && _seatnum > 0);
	}

	Vehicle::Vehicle()
	{
		setEmpty();
	}
	Vehicle::Vehicle(int _spd, int _seatnum)
	{
		setEmpty();
		if (!(_spd >= MIN_SPEED || _seatnum == 0)) { setEmpty(); }
		else
		{
			m_speed = _spd;
			m_noOfSeats = _seatnum;
		}	
	}

	void Vehicle::setEmpty()
	{
		m_speed = 0;
		m_noOfSeats = 0;
	}

	bool Vehicle::finetune()
	{
		bool result = (m_speed > MAX_SPEED) ? (m_speed = MIN_SPEED) : (false);			
		if (true) { return result; }
			else { cout << "The car cannot be tuned" << endl;}	
	}

	ostream& Vehicle::display(ostream& os = cout) const
	{
		if ((m_speed >= MIN_SPEED && m_noOfSeats > 0))
		{
			os << "|" << m_speed << "|" << m_noOfSeats << endl;
			if (m_speed > MAX_SPEED)
			{
				os << "Car has to be fine tuned for speed limit" << endl;
			}
			else if (m_speed == 0 && m_noOfSeats == 0)
			{
				os << "This Car is not initiated" << endl;
			}
		}
		
		return os;
	}

	istream& Vehicle::input(istream& in = cin)
	{
		cout << "Enter the Vehicle`s speed: ";
			in >> m_speed;
		cout << "Enter no of seats: ";
			in >> m_noOfSeats;	
		set(m_speed, m_noOfSeats);
		return in;
	}

	ostream& operator<<(ostream& os, const Vehicle& v)
	{
		v.display(os);
		return os;
	}

	istream& operator>>(istream& in, Vehicle& V)
	{
		V.input(in);
		return in;
	}

}