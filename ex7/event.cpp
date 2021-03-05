/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca

	May 31, 2020

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> 
#include <iomanip> 
#include "event.h"

using namespace std;
unsigned int g_sysClock; // redeclaration
namespace sdds
{
	void Event::setDescription(const char* desc)
	{		
		if (desc)
		{
			clearMemory();
			m_desc = new char[strlen(desc) + 1];
			strcpy(m_desc, desc);
			m_time = g_sysClock;
		}
		else
		{
			clearMemory();
		}			
  	}
		
	bool Event::isEmpty() const
	{
		return !(m_desc != nullptr && m_desc[0] != '\0');
	}

	void Event::setEmpty()
	{
		m_desc = nullptr;
		m_time = 0;
	}

	void Event::clearMemory()
	{
		delete[] m_desc;
		m_desc = nullptr;
	}

	Event::~Event()
	{
		clearMemory();
	}

	void Event::display() const
	{
		static int counter = 0;
		counter++;
		if (isEmpty())
		{
			cout.width(3);
			cout.fill(' ');
			cout << counter << ". " << "[ No Event ]" << endl;
		}
		else
		{
			int hr = m_time / 3600;
			int rem = m_time % 3600;
			int min = rem / 60;
			int sec = rem % 60;
		
			cout.width(3);
			cout.fill(' ');
			cout << counter << ". ";
			cout << setw(2) << setfill('0');
			cout << hr << ":";
			cout << setw(2) << setfill('0');
			cout << min << ":";
			cout << setw(2) << setfill('0');
			cout << sec << " -> ";
			cout << m_desc << endl;
		}

	}

	Event::Event(const Event& e)
	{
		setEmpty();
		if (e.m_desc)
		{
			setDescription(e.m_desc);
			m_time = e.m_time;
		}
	}

	Event& Event::operator=(const Event& e)
	{
		setDescription(e.m_desc);
		m_time = e.m_time;
		return *this;
	}

}