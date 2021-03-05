/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - LAB4
*/

#include <string>
#include <stdexcept>
#include <iostream>
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
namespace sdds
{
	template<class T>
	class Collection
	{
		T* m_collection = nullptr;
		std::string m_name = "";
		size_t m_length = 0;
		void(*pointer)(const Collection<T>& temp, const T&);
	public:
		Collection(std::string name)
		{
			m_collection = nullptr;
			pointer = nullptr;
			m_name = name;
			m_length = 0;
		}
		~Collection()
		{
			delete[] m_collection;
			m_collection = nullptr;
		}
		const std::string& name() const
		{
			return m_name;
		}
		size_t size() const
		{
			return m_length;
		}
		void setObserver(void(*observer)(const Collection<T>&, const T&))
		{
			pointer = observer;
		}
		Collection<T>& operator+=(const T& item)
		{
			bool flag = false;
			if (m_collection != nullptr)
			{
				for (unsigned i = 0; i < m_length; i++)
				{
					if (m_collection[i].title() == item.title())
						flag = true;
				}
			}
			if (flag == false)
			{
				T* temp = m_collection;
				m_length++;
				m_collection = new T[m_length];
				for (unsigned i = 0; i < m_length - 1; i++)
				{
					m_collection[i] = temp[i];
				}
				m_collection[m_length - 1] = item;
				if (pointer != nullptr)
					pointer(*this, item);
				delete[] temp;
				temp = nullptr;					
			}
			return *this;
		}
		T& operator[](size_t idx) const
		{
			if (idx >= m_length)
			{
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_length) + "] items.");
			}
			else
				return m_collection[idx];
		}
		T* operator[](std::string title) const
		{
			for (unsigned i = 0; i < this->size(); i++)
			{
				if (m_collection[i].title() == title)
					return &m_collection[i];
			}
			return nullptr;
		}

		friend std::ostream& operator<<(std::ostream& os, const Collection& temp)
		{
			for (unsigned i = 0; i < temp.size(); i++)
			{
				os << temp[i];
			}
			return os;
		}
	};
}
#endif // !SDDS_COLLECTION_H


