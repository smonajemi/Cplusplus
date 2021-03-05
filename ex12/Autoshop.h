/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - DIY 6
*/
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <vector>
#include <list>
#include "Vehicle.h"
namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;

	public:
		~Autoshop();
		Autoshop& operator +=(Vehicle*);
		void display(std::ostream&) const;
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles)
		{
			for (auto ite = m_vehicles.begin(); ite != m_vehicles.end(); ++ite)
			{
				if (test(*ite))
					vehicles.push_back(*ite);
			}
		}
	};
	
}
#endif // !SDDS_AUTOSHOP_H
