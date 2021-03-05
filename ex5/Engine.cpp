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
using namespace std;
#include "Engine.h"


namespace sdds
{
	/*
	void Engine::setEngine(const Engine e)
	{
		m_engine_size = e.m_engine_size;
	}
	*/

	void Engine::setEmpty()
	{
		m_engine_type[0] = 0;
		m_engine_size = 0;
	}

	Engine::Engine()
	{
		setEmpty();
	}

	Engine::Engine(const char* type, double size)
	{
		bool Engine_type = type != nullptr && type[0] != '\0';
		bool Engine_size = size > 0;

		if (Engine_type && Engine_size)
		{
			strncpy(m_engine_type, type, ENGINETYPE_SIZE + 1);
			m_engine_size = size;						
		}
		else
		{
			setEmpty();
		}
		
	}

	void Engine::display() const
	{
		cout << m_engine_size << " liters - " << m_engine_type << endl;
	}

	double Engine::getSize() const
	{
		return m_engine_size;
	}

}
