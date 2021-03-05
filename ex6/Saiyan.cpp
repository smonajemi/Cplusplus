#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Saiyan.h"
using namespace std;

namespace sdds
{
	Saiyan::Saiyan()
	{
		setEmpty();
	}

	Saiyan::Saiyan(const char* name, int dob, int power)
	{
		bool Saiyan_name = name != nullptr && name[0] != '\0';
		bool Saiyan_dob = dob < 2020;
		bool Saiyan_power = power > 0;

		if (Saiyan_name && Saiyan_dob && Saiyan_power)
		{
			m_size = 0;
			m_size = strlen(name);
			(*this).m_name = new char[m_size + 1]; // Arithmetic overflow?
			strcpy(this->m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = false;
		}
		else
		{
			setEmpty();
		}
	}

	Saiyan::~Saiyan()
	{
		clearMemory();
	}

	bool Saiyan::isSuper() const
	{
		return m_super;
	}

	bool Saiyan::isValid() const
	{
		return m_name != nullptr && m_dob != 0;
	}

	bool Saiyan::hasLost(Saiyan& other)
	{
		other.powerup();
		this->powerup();
		return !(other.m_power < this->m_power);

	}

	void Saiyan::setEmpty()
	{
		m_name = nullptr;
		m_size = 0;
		m_dob = 0;
		m_power = 0;
		m_level = 0;
		m_super = 0;
	}

	void Saiyan::display() const
	{
		if (!isValid())
		{
			cout << "Invalid Saiyan!" << endl;
		}
		else
		{
			cout << m_name << endl;
			cout << "DOB: " << m_dob << " Power: " << m_power << endl;

			if (m_super == true)
			{
				cout << "Super Saiyan Ability: " << "Super Saiyan." << endl;
				cout << "Super Saiyan level is: " << m_level << endl;
			}
			else
			{
				cout << "Super Saiyan Ability: " << "Not super Saiyan." << endl;
				cout << endl;
			}
		}
	}

	void Saiyan::powerup()
	{
		if (m_super == true)
		{
			m_power = m_power * (m_level + 1);
		}
	}

	void Saiyan::clearMemory()
	{
		delete[] m_name;
		m_name = nullptr;
		m_size = 0;
	}

	void Saiyan::set(const char* name, int dob, int power, int level, bool super)
	{
		clearMemory();

		m_size = strlen(name);
		(*this).m_name = new char[m_size + 1];
		strcpy(this->m_name, name);

		m_dob = dob;
		m_power = power;
		m_super = super;
		m_level = level;

		if (!isValid())
		{
			setEmpty();
		}
	}

}


