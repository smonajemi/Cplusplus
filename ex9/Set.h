/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - DIY 3
*/
#include <iostream>
#ifndef SDDS_SET_H
#define SDDS_SET_H
namespace sdds
{
	template <typename T, int N>
	class Set
	{
		T m_array[N] {};
		size_t m_number = 0;

	public:
		Set() {};
		size_t size() const
		{
			return m_number;
		}
		const T& operator[](size_t idx) const
		{
			return m_array[idx];
		}
		void operator+=(const T& item)
		{	
			if (m_number < N)
				m_array[m_number++] = item;	
		}
	};
}
#endif // !SDDS_SET_H
