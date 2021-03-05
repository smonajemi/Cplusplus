/*
	Sina Monajemi
	021-324-124
	smonajemi@myseneca.ca
	OOP244-NBB
	March 10, 2020
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
#include "Basket.h"


namespace sdds
{


	Basket::Basket()
	{
		setEmpty();
	}

	Basket::Basket(const char* fruitName, int quantity, double basketPrice)
	{
		setEmpty(); // initilizing to Emptystate
		bool validate = fruitName != nullptr && quantity > 0 && basketPrice > 0.0;
		
		if (validate)
		{
			setName(fruitName);
			setQty(quantity);
			setPrice(basketPrice);
		}
		else
		{
			setEmpty();
		}

		(fruitName == nullptr) ? setEmpty() : setName(fruitName);

	}

	Basket::Basket(const Basket& src)
	{
		setEmpty();

		setName(src.m_fuitName);
		setQty(src.m_qty);
		setPrice(src.m_price);		
	}

	Basket::~Basket()
	{
		clearMemory();
	}

	bool Basket::isValid() const
	{
		return (m_fuitName != nullptr && m_qty > 0 && m_price > 0.0);
	}

	bool Basket::isempty() const
	{
		return !(isValid());
	}

	bool Basket::addPrice(double prc)
	{
		return (prc > 0) ? (m_price += prc) : false;
	}

	void Basket::setEmpty()
	{	
		m_fuitName = nullptr;
		m_qty = 0;
		m_price = 0.0;		
	}

	void Basket::setName(const char* fruitName)
	{
			clearMemory();

			int m_size = 0;
			m_size = (strlen(fruitName) + 1);
			m_fuitName = new char[m_size];
			strcpy(m_fuitName, fruitName);
	}

	void Basket::setQty(int qty)
	{
		(qty >= 0) ? (m_qty = qty) : (m_qty = 0);
	}

	void Basket::setPrice(double prc)
	{
		(prc >= 0.0) ? (m_price = prc) : (m_price = 0.0);
	}

	void Basket::clearMemory()
	{
		delete [] m_fuitName;
		m_fuitName = nullptr;
	}

	ostream& Basket::display(ostream& os = cout ) const
	{
		if (isempty())
		{
			os << "The Basket has not yet been filled" << endl;
		}
		else
		{
			os << "Basket Details" << endl;
			os << "Name: " << m_fuitName << endl;
			os << "Quantity: " << m_qty << endl;
			os.setf(std::ios::fixed); os.precision(2); os << "Price: " << m_price << std::endl;
		}
		return os;
	}

	Basket& Basket::operator=(const Basket& src)
	{
		if (&src)
		{
			setName(src.m_fuitName);
			setQty(src.m_qty);
			setPrice(src.m_price);
		}
		return *this;
	}

	bool Basket::operator==(const Basket& bsk)
	{
		return (!strcmp(m_fuitName, bsk.m_fuitName) && m_qty == bsk.m_qty && m_price == bsk.m_price);
	}

	bool Basket::operator!=(const Basket& bsk)
	{
		return !(strcmp(m_fuitName, bsk.m_fuitName) && m_qty != bsk.m_qty && m_price != bsk.m_price);
	}

	ostream& operator<<(ostream& os, const Basket& bsk)
	{
		bsk.display(os);
		return os;
	}

}