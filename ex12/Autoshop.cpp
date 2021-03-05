/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - DIY 6
*/
#include "Autoshop.h"
using namespace std;
namespace sdds
{
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle); // adding a new element to the end
		return *this;
	}
	void Autoshop::display(ostream& os) const
	{
		os << "--------------------------------" << endl;
		os << "| Cars in the autoshop!        |" << endl;
		os << "--------------------------------" << endl;
		for (auto ite = m_vehicles.begin(); ite != m_vehicles.end(); ++ite)
		{
			(*ite)->display(os); os << endl;
		}
		os << "--------------------------------" << endl;
	}
	Autoshop::~Autoshop()
	{
		//while (!m_vehicles.empty())
		//{
		//	delete m_vehicles.back(); // returns a reference to the last element
		//	m_vehicles.pop_back(); // removes and destroys the last element
		//}
		for (vector<Vehicle*>::iterator ite = m_vehicles.begin(); ite != m_vehicles.end(); ++ite) 
			delete* ite;
	}
}