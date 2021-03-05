/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - DIY 3
*/
#include <iomanip>
#include <string>
#include "Pair.h"
#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H
namespace sdds
{

	template<typename K, typename V>
	class PairSummable : public Pair<K, V>
	{
		static V m_initialValue;
		static size_t m_minNumber;
		
	public:
		PairSummable() {}
		PairSummable(const K& key, const V& value) : Pair<K,V>(key,value)
		{
			if (m_minNumber < key.size())
				m_minNumber = key.size();
		}
		V sum(const K& key, const V& val) const
		{
			return key == this->key() ? (val + this->value()) : val;
		}
		void display(std::ostream& os) const
		{
			os << std::left << std::setw(m_minNumber);
			Pair<K, V>::display(os);
			os << std::right;
		}
		static const V& getInitialValue()
		{
			return m_initialValue;
		}
	};

	 template<typename K,typename V>
	 size_t PairSummable<K, V>::m_minNumber = 0;
	 template<>
	 std::string PairSummable<std::string, std::string>::m_initialValue = std::string("");
	 template<>
	 int PairSummable<std::string, int>::m_initialValue = 0;
	 template<>
	 std::string PairSummable<std::string, std::string>::sum(const std::string& k, const std::string& v) const
	 {
		 if (key() == k)
			 return v == "" ? value() : v + ", " + value();
		 else
			 return v;
	 }

	
}
#endif // !SDDS_PAIRSUMMABLE_H
