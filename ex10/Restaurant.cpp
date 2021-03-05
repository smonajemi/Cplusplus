
/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - DIY4
*/
#include "Restaurant.h"
using namespace std;
namespace sdds
{
	void Restaurant::setEmpty()
	{
		m_ResArray = nullptr;
		m_cnt = 0u;
		m_today = 0u;
	}
	void Restaurant::clearMemory()
	{
		delete[] m_ResArray;
		m_ResArray = nullptr;
	}
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt)
	{
		m_ResArray = new Reservation[cnt];
		m_cnt = cnt;
		for(size_t i = 0u; i < cnt; i++)
			m_ResArray[i] = *reservations[i];
	}
	Restaurant::~Restaurant()
	{
		clearMemory();
	}
	Restaurant::Restaurant(const Restaurant& src)
	{
		setEmpty();
		*this = src;
	}
	Restaurant& Restaurant::operator=(const Restaurant& src)
	{
		setEmpty();
		if (this != &src)
		{
			m_today = src.m_today;
			m_cnt = src.m_cnt;
			m_ResArray = new Reservation[m_cnt];
			for (size_t i = 0u; i < m_cnt; i++)
			{
				m_ResArray[i] = src.m_ResArray[i];
			}
		}
		return *this;
	}
	Restaurant::Restaurant(Restaurant&& src)
	{
		*this = move(src);
	}
	Restaurant& Restaurant::operator=(Restaurant&& src)
	{
		if (this != &src)
		{
			m_cnt = src.m_cnt;
			clearMemory();
			m_ResArray = src.m_ResArray;
			src.setEmpty();
		}
		return *this;
	}
	size_t Restaurant::size() const
	{
		return m_cnt;
	}
	std::ostream& operator<<(std::ostream& os, const Restaurant& res)
	{
		os << "--------------------------\n";
		os << "Fancy Restaurant" << endl;
		os << "--------------------------\n";
		if (res.m_cnt == 0)
			os << "The object is empty!" << endl;
		for (size_t i = 0u; i < res.m_cnt; i++)
			os << res.m_ResArray[i];
		os << "--------------------------\n";
		return os;
	}
}