/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - DIY4
*/
#include "Reservation.h"
#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
namespace sdds
{
	class Restaurant
	{
		Reservation* m_ResArray = nullptr;
		size_t m_cnt = 0u;
		size_t m_today = 0u;

	
		void setEmpty();
		void clearMemory();

	public:
		//(de)-constructors/
		Restaurant() {};
		Restaurant(Reservation* reservations[], size_t cnt);
		~Restaurant();
		//copy constructor
		Restaurant(const Restaurant&);
		Restaurant& operator=(const Restaurant&);
		//move constructor
		Restaurant(Restaurant&&);
		Restaurant& operator=(Restaurant&&);
		size_t size() const; //query to return size;
		//friend helper operator
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
	};
}
#endif // !SDDS_RESTAURANT_H
