/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - DIY 3
*/
#include <iostream>
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
namespace sdds
{
	template<typename K, typename V>	
	class Pair
	{		
		K m_key {};
		V m_value {};

	public:
		Pair() {};
		Pair(const K& key, const V& value)
		{
			m_key = key;
			m_value = value;
		}
		const K& key() const
		{
			return m_key;
		}
		const V& value() const
		{
			return m_value;
		}
		virtual void display(std::ostream& os) const
		{
			os << key() << " : " << value() << std::endl;	
		}		
	};
	template<typename K, typename V>
	std::ostream& operator<<(std::ostream& os, const Pair <K, V>& pair)
	{
		pair.display(os);
		return os;
	}
}
#endif // !SDDS_PAIR_H
