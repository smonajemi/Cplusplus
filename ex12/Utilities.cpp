/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - DIY 6
*/
#include <iostream>
#include <sstream>
#include "Utilities.h"
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"
using namespace std;
namespace sdds
{
	Vehicle* createInstance(istream& is)
	{
		string data;
		char type = '\0';
		char delim = '\0';
		getline(is, data);
		stringstream str(data); // for breaking words
		str >> type >> delim;

		if (str)
		{
			switch (type)
			{
			case 'C':
			case 'c':
				return new Car(str);
				break;

			case 'R':
			case 'r':
				return new Racecar(str);
				break;

			default:
				throw type;
				break;
			}
		}
		return nullptr;
	}
}