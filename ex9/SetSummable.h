/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - DIY 3
*/
#include "Set.h"
#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
namespace sdds
{
	
	template <typename T, size_t N, typename K, typename V>
	class SetSummable : public Set<T,N>
	{
	public:
		V accumulate(const K& key) const
		{
			auto sum = T::getInitialValue();
			for (size_t i = 0; i < this->size(); i++)
			{
				sum = (*this)[i].sum(key, sum);
			}
			return sum;
		}
	};
}
#endif // !SDDS_SETSUMMABLE_H
