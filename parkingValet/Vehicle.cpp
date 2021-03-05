/*
File: MILESTONE 6

Name: SINA MONAJEMI
Email: smonajemi@myseneca.ca
Student Number: 021-324-124

Date: April 12, 2020 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
#include "Vehicle.h"

namespace sdds
{
	Vehicle::Vehicle(const char* LicenceP, const char*  make_model)
	{
		bool inValid = (LicenceP == nullptr || LicenceP[0] == '\0' || strlen(LicenceP) > MAX_LICENCEPLATE || make_model == nullptr || make_model[0] == '\0' || strlen(make_model) < 2);
		if (inValid)
			setEmpty();
		else
		{
			setLicence(LicenceP);			
			setMakeModel(LicenceP);
			setParkingSpot();
		}
	}
	Vehicle::~Vehicle()
	{
		clearMemory();
	}

	void Vehicle::clearMemory()
	{
		delete[] m_make_model;
		m_make_model = nullptr;
	}

	void Vehicle::setCapital(char* src)
	{
		for (int i = 0; (unsigned)i < strlen(src); i++)
		{
			if (src[i] >= 'a' && src[i] <= 'z')
			{
				src[i] -= 32;
			}
		}
	}

	void Vehicle::setEmpty()
	{
		m_licence[0] = '\0';
		delete[] m_make_model;
		m_make_model = nullptr; 
		m_spotnum = 0;
	}
	bool Vehicle::isEmpty() const
	{
		return ((m_licence[0] == '\0' || m_licence == nullptr) && m_make_model == nullptr);
	}

	char Vehicle::getLicencePlate() const
	{
		return m_licence[MAX_LICENCEPLATE];
	}

	char* Vehicle::getMakeModel() const
	{
		return m_make_model;
	}
	void Vehicle::setMakeModel(const char* src)
	{
		clearMemory();
		m_make_model = new char[100];
		strcpy(m_make_model, src);		
	}
	void Vehicle::setLicence(const char* src)
	{
		strncpy(m_licence, src, MAX_LICENCEPLATE);
		setCapital(m_licence);
		m_licence[MAX_LICENCEPLATE] = '\0';
	}
	int Vehicle::getParkingSpot() const
	{
		return m_spotnum;
	}
	void Vehicle::setParkingSpot(int num)
	{
		if (num <= 0)
			setEmpty();
		else
		m_spotnum = num;
	}

	bool Vehicle::setNum()
	{
		return validation;
	}

	std::ostream& Vehicle::write(std::ostream& os) const
	{
		if (isEmpty())
		{
			os << "Invalid Vehicle Object" << '\n';
		}
		else 
		{
			if (this->isCsv())
			{
				os << m_spotnum << "," << m_licence << "," << m_make_model << ",";
			}
			else
			{
				if (m_spotnum == 0)
					os << "Parking Spot Number: " << "N/A" << endl;
				else
					os << "Parking Spot Number: " << m_spotnum<< endl;
					os << "Licence Plate: " << m_licence << endl;
					os << "Make and Model: " << m_make_model << endl;
			}			
		}		
		return os;
	}
	std::istream& Vehicle::read(std::istream& is)
	{		
		bool done = false;
		bool exit = false;
		
		if (!Vehicle::isCsv())
		{
			setEmpty();
			char temp[100] = { 0 };
			cout << "Enter Licence Plate Number: "; 
			while (!exit)
			{
				is.getline(temp, 100);
				if (strlen(temp) > 1 && strlen(temp) <= MAX_LICENCEPLATE)
				{
					setLicence(temp);
					exit = true;
				}
				else
				{
					cout << "Invalid Licence Plate, try again: ";
				}
			}		
				char str[250] = { 0 };
				cout << "Enter Make and Model: ";
				
				while (!done)
				{		
					is.getline(str, 250);
					
					if (strlen(str) >= 2 && strlen(str) + 1 <= 60)
					{
						setMakeModel(str);
						done = true;
					}
					else
					{
						cout << "Invalid Make and model, try again: ";
					}
				}			
		}
		else
		{
			setEmpty();
			m_spotnum = 0;
			
			char* m_vehicle_objects = new char[250];
			int temp = 0;
			is.getline(m_vehicle_objects, 250, '\n');
			char* delim = strtok(m_vehicle_objects, ",");
	
					m_spotnum = atoi(delim);
					delim = strtok(nullptr, ",");	
			
					setLicence(delim);				
					delim = strtok(nullptr, ",");
					
					setMakeModel(delim);
					delim = strtok(nullptr, ",");		
						
					temp = atoi(delim);
					if (temp != 0)
						validation = true;
					else
					validation = false;
					
					delim = strtok(nullptr, ",");
				
					delete[] m_vehicle_objects;
					m_vehicle_objects = nullptr;
		}

		return is;
	}

	bool Vehicle::operator==(const char* Rvalue) const
	{
		bool exit = false;
		char str[MAX_LICENCEPLATE] = { 0 };
		//char* temp = new char[MAX_LICENCEPLATE + 1];
		strcpy(str, Rvalue);

			for (int i = 0; (unsigned)i < strlen(Rvalue); i++)
			{
				if (str[i] >= 'a' && str[i] <= 'z')
				{
					str[i] -= 32;
				}
			}
			
			//if (m_licence[0] != '\0')
			//	strcpy(temp, m_licence);

			if (strcmp(m_licence,str) == 0)
			{
				exit = true;
			}
			else
			{
				exit = false;
			}
			//delete[] temp;
			//temp = nullptr;

			return exit;
	}

	bool Vehicle::operator==(const Vehicle& v) const
	{
		return v.getLicencePlate() == v.getLicencePlate();
	}

	std::ostream& operator<<(std::ostream& os, const Vehicle& v)
	{
		return v.write(os);
	}
	std::istream& operator>>(std::istream& is, Vehicle& v)
	{
		return v.read(is);
	}
}