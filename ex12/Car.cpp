/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - DIY 6
*/
#include "Car.h"
#include <iomanip>
#include <algorithm> 

#include <string>
using namespace std;
namespace sdds
{
	std::string Car::trim(string& str)
	{		
		while (str.begin(), str[0] == ' ')
			str.erase(0, 1);
		while (str.length() > 0 && str[str.length() - 1] == ' ')
			str.erase(remove(str.begin(), str.end(), ' '));

		return str;	
	}
	Car::Car(istream& is)
	{
		string temp;
		getline(is, temp, ',');
		m_makemodel = trim(temp);
		getline(is, temp, ',');
		trim(temp);
		if (temp == "" || temp == "n")
			m_condition = "new";
		else if (temp == "b")
			m_condition = "broken";
		else if (temp == "u")
			m_condition = "used";
		else
			throw "Invalid record!";
		getline(is, temp, ',');
		try
		{
			m_maxspeed = stoi(trim(temp));
		}
		catch (...)
		{
			throw "Invalid record!";
		}	
	}
	std::string Car::condition() const
	{
		return m_condition;
	}
	double Car::topSpeed() const
	{
		return m_maxspeed;
	}
	void Car::display(ostream& os) const
	{
		os << "| " << setw(10) << m_makemodel << " | " << setw(6) << left << this->condition()
			<< " | " << setw(6) << setprecision(2) << fixed << right << this->topSpeed() << " |";
	}
	
}