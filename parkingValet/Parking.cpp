/*
File: MILESTONE 6

Name: SINA MONAJEMI
Email: smonajemi@myseneca.ca
Student Number: 021-324-124

Date: April 12, 2020 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include<string.h>
#include <fstream>
using namespace std;
#include "Parking.h"
#include "Menu.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Utils.h"
namespace sdds
{

	Parking::Parking(const char* src, int noOfSpots) // or to display the title I could use : m_Parking("Title");
	{

		if (noOfSpots < 10 || noOfSpots > MAX_NUMPARKING_SPOTS)
			setEmptyNewVariables();
		else
			m_noOfSpots = (noOfSpots);
		if (src != nullptr && src[0] != 0)
			setName(src);
		else
		{
			setEmptyState();
		}
		if (!loadData())
		{
			cout << "Error in data file" << endl;
			setEmptyState();
		}
		else
		{
			populateParkingMenu();
			populateVehicleMenu();
		}
	}

	Parking::~Parking()
	{
		saveData();
		setEmptyNewVariables();
		clearMemory();
	}

	void Parking::clearMemory()
	{
		setEmptyState();
		m_Parking = nullptr;
		m_Vehicle = nullptr;
	}

	void Parking::setEmptyState()
	{
		delete[] m_filename;
		m_filename = nullptr;
	}

	void Parking::setName(const char* src)
	{
		setEmptyState();
		if (src[0] != '\0' && src != nullptr)
		{
			m_filename = new char[strlen(src) + 1];
			strcpy(m_filename, src);
		}
	}

	void Parking::populateParkingMenu()
	{
		m_Parking = Menu("Parking Menu, select an action:", 0);
		m_Parking << ("Park Vehicle");
		m_Parking << ("Return Vehicle");
		m_Parking << ("List Parked Vehicles");
		m_Parking << ("Close Parking (End of day)");
		m_Parking << ("Exit Program");
	}

	void Parking::populateVehicleMenu()
	{
		m_Vehicle = Menu("Select type of the vehicle:", 1);
		m_Vehicle << ("Car");
		m_Vehicle << ("Motorcycle");
		m_Vehicle << ("Cancel");
	}

	void Parking::ParkVehicle()
	{
		int i = 0;
		bool done = false;
		bool exit = false;
		Vehicle* vehicle = nullptr;

		switch (m_Vehicle.run())
		{
		case 1:
			for (i = 0;; i++)
				if (array[i] == nullptr)
				{
					vehicle = new Car();
					done = true;
					break;
				}

			break;
		case 2:
			for (i = 0;; i++)
				if (array[i] == nullptr)
				{
					vehicle = new Motorcycle();
					done = true;
					break;
				}
			break;
		case 3:
			cout << "Parking cancelled" << endl;
			break;
		}
		if (done == true)
		{
			while (!exit)
			{
				array[i] = vehicle;
				vehicle->read();
				vehicle->setParkingSpot(i + 1);
				m_noOfParkedVehicles++;
				cout << "\nParking Ticket" << endl;
				vehicle->write();
				cout << "\n";
				exit = true;
			}
		}
	
	}

	void Parking::parkingStatus() const
	{
		cout << "****** Seneca Valet Parking ******" << endl;
		cout << "*****  Available spots: ";
		cout.width(4);
		cout << left << m_noOfSpots - m_noOfParkedVehicles << " *****";
		cout << endl;
	}

	void Parking::returnVehicle()
	{

		char temp[8] = { 0 };
		bool exit = false;
		bool valid = false;
		int i;
		cout << "Return Vehicle" << endl;
		cout << "Enter Licence Plate Number: ";
		while (!exit)
		{
			cin.getline(temp, 25, '\n');
			if (strlen(temp) < 1 || strlen(temp) > MAX_LICENCEPLATE) {
				cout << "Invalid Licence Plate, try again: ";
			}
			else
				exit = true;
		}
		if (exit)
		{
			for (i = 0; i < m_noOfSpots; i++)
			{
				if (array[i] != nullptr && *array[i] == temp)
				{
					array[i]->setCsv(false);
					cout << "\nReturning: \n";
					array[i]->write();
					cout << '\n';
					m_noOfParkedVehicles--;
					delete array[i];
					array[i] = nullptr;
					valid = true;
				}
				
			}
				
		}	
		if (valid != true)
			cout << "Licensce plate " << temp << " Not found" << endl;

	}

	void Parking::Parkinglist() const
	{
		cout << "*** List of parked vehicles ***" << endl;

		for (int i = 0; i < m_noOfSpots; i++)
		{

			if (array[i] != nullptr)
			{
				array[i]->setCsv(false);
				cout << *array[i];
				cout << "-------------------------------\n";
			}

		}
	}

	void Parking::saveData()
	{
		if (!isEmpty()) {
			std::ofstream fout(m_filename);
	
			for (int i = 0; i < m_noOfSpots; i++) {
				if (array[i] != nullptr) {
					array[i]->setCsv(true);
					array[i]->write(fout);
				}
			}
			fout.close();
		}
	}


	bool Parking::checkValidation(int noOfSpots, int noOfParkedV)
	{
		return (noOfSpots < MAX_NUMPARKING_SPOTS) && (noOfParkedV < m_noOfSpots);
	}

	int Parking::NumOfParkedVehicles()
	{
		for (int i = 0; i < 10; i++)
		{
			if (array[i] != nullptr)
				m_noOfParkedVehicles++;
		}
		return m_noOfParkedVehicles;
	}

	void Parking::setEmptyNewVariables()
	{
		for (int i = 0; i < m_noOfSpots; i++)
		{
			delete array[i];
			array[i] = nullptr;
		}
		m_noOfSpots = 0;
		m_noOfParkedVehicles = 0;
	}

	int Parking::run()
	{
		bool done = false;
		if (!isEmpty())
		{
			while (!done) {

				parkingStatus();
				switch (m_Parking.run()) {
				case 1:
					if (m_noOfParkedVehicles < m_noOfSpots)
						ParkVehicle();
					else
						cout << "Parking is full" << endl;					
					break;
				case 2:
					returnVehicle();
					break;
				case 3:
					Parkinglist();
					break;
				case 4:
					if (closeParking() == true)
						done = true;
					break;
				case 5:
					if (exitProgram() == true)
						done = true;
					break;
				}
			}
			if (isEmpty())
			{
				return 1;
			}
			else { return 0; }
		}
		return done;
	}

	bool Parking::loadData()
	{
		Vehicle* _obj = nullptr;
		string read;


		if (!isEmpty())
		{
			ifstream fin(m_filename);
			if (!fin.good())
				return true;

				for (int i = 0; i < m_noOfSpots; i++)
				{
					getline(fin, read, ',');

					if (read[0] == 'C')
					{
						_obj = new Car();
					}
					if (read[0] == 'M')
					{
						_obj = new Motorcycle();
					}

					if (read != "")
					{
						_obj->setCsv(true);
						_obj->read(fin);

						if (_obj != nullptr)
						{
							array[i] = _obj;
							_obj = nullptr;
							m_noOfParkedVehicles++;
							delete _obj;
							_obj = nullptr;
						}
						else
						{
							delete _obj;
							_obj = nullptr;
							break;
						}

					}
				}
			//fin.close();
		}
		
		return true;

	}

	bool Parking::isEmpty() const
	{
		return (m_filename == nullptr);
	}

	bool Parking::closeParking()
	{
		bool exit = false;
		if (Parking::isEmpty())
		{
			cout << "Closing Parking" << endl;
			return true;
		}
		else
			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		if (yes() != true)
		{
			cout << "Aborted!" << endl;
			exit = false;
		}
		else
		{
			cout << "Closing Parking" << endl;
			for (int i = 0; i < m_noOfSpots; i++)
			{
				if (array[i] != nullptr)
				{
					cout << "\nTowing request" << endl;
					cout << "*********************" << endl;
					array[i]->setCsv(false);
					cout << *array[i];
					delete array[i];
					array[i] = nullptr;
				}

			}
			exit = true;
		}
		return exit;
	}

	bool Parking::exitProgram()
	{
		bool exit = false;
		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		if (yes())
		{
			cout << "Exiting program!" << endl;
			exit = true;
		}
		return exit;

	}
}



