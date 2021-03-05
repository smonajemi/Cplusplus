/*
	Sina Monajemi
	021-324-124
	smonajemi@myseneca.ca
	OOP244-NBB
	Feb 20, 2020
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
#include "Ship.h"


namespace sdds
{
	void Ship::setEmpty()
	{
		m_engine = nullptr;
		m_ship_type = nullptr;
		m_num = 0;
		m_distance = 0.0;
	}

	Ship::Ship()	
	{
		setEmpty();
	}

	Ship::Ship(const char* type,const Engine* engine, int size)
	{
		if (size > 0 && strlen(type) <= 6 && type != nullptr && type[0] != 0)
		{
			int count = 0;
			setEmpty();
			//cout << "Engine & Ship: Memory Allocation: " << endl;
			m_engine = new Engine[FIXED_SIZE];

			int length = strlen(m_ship_type + 1);
			m_ship_type = new char[length];

			strcpy(m_ship_type, type);

			for (int i = 0; i < size; i++)
			{
				if (engine[i].getSize() > 0)
				{
					count++; // length of its size
				}
				m_engine[i] = engine[i]; // copyig the objects
			}m_num = count;
		
		}
		else
		{
			setEmpty();
		}
	}
	
	Ship::~Ship()
	{
		clearMemory();
	}

	void Ship::clearMemory()
	{
		//cout << "Memory De-allocation: " << endl;
		delete[] m_engine;
		delete[] m_ship_type;
		setEmpty();
	}

	bool Ship::empty() const
	{
		return m_num > 0;
	}

	float Ship::calculatePower() const
	{
		float power = 0.0;
		for (int i = 0; i < m_num; i++)
		{
			power += m_engine[i].getSize() * 5;
		}
		return power;
	}

	void Ship::display() const
	{
		if (empty())
		{
			cout << m_ship_type << "-";
			cout.setf(ios::fixed); 
			cout << setprecision(2) << setw(6) << calculatePower() << endl;

			for (int i = 0; i < m_num; i++)
			{
				cout.setf(ios::fixed);
				cout.precision(2);
				m_engine[i].display();
			}
		}
		else
		{
			cout << "No available data" << endl;
		}
	}

	Ship& Ship::operator+=(const Engine& e)
	{		
		if (m_num < 10 && m_num > 0)
		{
			//cout << "Memory Allocation: " << endl;

			Engine* newEngine = new Engine[m_num + 1];
			//if (newEngine == NULL)
			//{
			//	cout << "NOT ALLOCATED" << endl;
			//}

			for (int i = 0; i < m_num; i++)
			{
				newEngine[i] = m_engine[i]; // copying arrays contents 
			}

			newEngine[m_num++] = e;
			//cout << "Memory De-allocation: " << endl;
			delete[] m_engine;
			m_engine = newEngine;
		}
		else
		{
			cout << "The ship doesn't have a type! Engine cannot be added!" << endl;
		}
		return *this;	
	}

	bool operator==(const Ship& x, const Ship& y)
	{
		return x.calculatePower() == y.calculatePower();
	}

	bool operator<(const Ship& x, double max)
	{
		return x.calculatePower() < max;		
	}

}
