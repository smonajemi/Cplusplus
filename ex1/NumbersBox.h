/*
File Name: Lab_9 - OOP244-NBB
Name: Sina Monajemi
Student Number: 021-324-124
Email: smonajemi@myseneca.ca

Date: April 03, 2020
NumbersBox.h
----------------------------------------------------
*/

#include <iostream>
#include <string.h>
#ifndef SDDS_NUMBERSBOX_H
#define SDDS_NUMBERSBOX_H

namespace sdds
{
	const int CHAR_MAX_LENGTH = 15;

	template<typename T>
	class NumbersBox
	{
		char m_name[CHAR_MAX_LENGTH + 1]{};
		int m_size = 1; 
		T* m_items = nullptr;

	protected:
		int size() const;
		void set(int, const char*);
		void setItemsEmpty();

	public:
		NumbersBox() {};
		NumbersBox(int, const char*);
		~NumbersBox();
		T& operator[](int);
		std::ostream& display(std::ostream& os = std::cout) const;
		NumbersBox<T>& operator*=(const NumbersBox<T>&);
		NumbersBox<T>& operator+=(T);
	};

	/*----------------------------------------------------------------------------- Implementation ----------------------------------------------------------------------------*/

	template<typename T>
	inline int NumbersBox<T>::size() const
	{
		return m_size;
	}

	template<typename T>
	inline void NumbersBox<T>::setItemsEmpty()
	{
		delete[] m_items;
		m_items = nullptr;
	}

	template<typename T>
	inline void NumbersBox<T>::set(int len, const char* name)
	{
		m_size = len;
		strncpy(m_name, name, CHAR_MAX_LENGTH);
		m_name[CHAR_MAX_LENGTH] = '\0';
		m_items = new T[m_size];
	}

	template<typename T>
	inline NumbersBox<T>::NumbersBox(int len, const char* name)
	{
		bool valid = len >= 1 && name != nullptr;
		if (valid)
		{
			set(len, name);
		}
		else
		{
			setItemsEmpty();
			m_name[0] = '\0';
			m_size = 0;
		}
	}
	template<typename T>
	inline NumbersBox<T>::~NumbersBox()
	{
		setItemsEmpty();
		m_name[0] = '\0';
		m_size = 0;
	}
	template<typename T>
	inline T& NumbersBox<T>::operator[](int i)
	{
		return m_items[i % m_size];
	}
	template<typename T>
	inline std::ostream& NumbersBox<T>::display(std::ostream& os) const
	{
		if (m_name[0] == '\0')
		{
			os << "Empty Box" << std::endl;
			return os;
		}

		else
			os << "Box name: " << m_name << std::endl;
		for (int i = 0; i < size(); i++)
		{
			os << m_items[i];
			if (i < size() - 1)
				os << ", ";
		}
		os << "\n";

		return os;
	}
	template<typename T>
	inline NumbersBox<T>& NumbersBox<T>::operator*=(const NumbersBox<T>& other)
	{
		for (int i = 0; i < size(); i++)
		{
			if (m_size == other.m_size)
				other.m_items[i] *= m_items[i];
		}
		return *this;
	}
	template<typename T>
	inline NumbersBox<T>& NumbersBox<T>::operator+=(T num)
	{
		//std::cout << "Test1: " << num << std::endl;
		//std::cout << "Test2: " << m_items[3] << std::endl;

		T* newItem = new T[m_size + 1];
		for (int i = 0; i < size(); i++)
		{
			newItem[i] = m_items[i];
		}
		newItem[m_size++] = num;
		setItemsEmpty();
		m_items = newItem;		
		return *this;
	}
	template<typename T>
	std::ostream& operator<<(std::ostream& os, NumbersBox<T>& box)
	{
		return box.display(os);
	}
}
#endif // !SDDS_NUMBERSBOX_H


