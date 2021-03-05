/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - DIY 
*/
#include <iostream>
#include <fstream>
#include <string>
#include "RecordSet.h"

using namespace std;
namespace sdds
{
	void RecordSet::setEmpty()
	{
		m_array = nullptr;
		m_countRecords = 0;
	}
	void RecordSet::clearMemory()
	{
		delete[] m_array;
		m_array = nullptr;
	}

	void RecordSet::readFile(const char* m_fileName)
	{		
		ifstream file(m_fileName);
		if (file.good() && file.is_open())
		{
			string temp;
			while (getline(file, temp, ' '))
			{
				m_countRecords++;
			}
			file.clear();
			file.seekg(0);
			m_array = new string[m_countRecords];
			for (size_t i = 0; i < m_countRecords; i++)
			{
				getline(file, m_array[i], ' ');
			}
			file.close();
		}
		else
		{
			setEmpty();
		}
	}

	RecordSet::RecordSet(const char* fileName)
	{
		setEmpty();
		readFile(fileName);
	}

	RecordSet::RecordSet(const RecordSet& src)
	{
		setEmpty();
		*this = src;
	}

	RecordSet& RecordSet::operator=(const RecordSet& src)
	{
		setEmpty();
		if (src.m_array)
		{
			m_countRecords = src.m_countRecords;
			m_array = new std::string[m_countRecords];			
			for (size_t i = 0; i < m_countRecords; i++)
			{
				m_array[i] = src.m_array[i];
			}
		}
		return *this;
	}

	RecordSet::RecordSet(RecordSet&& src)
	{
		*this = move(src);
		src.setEmpty();
	}

	RecordSet& RecordSet::operator=(RecordSet&& src)
	{
		if (this != &src)
		{
			m_countRecords = src.m_countRecords;
			clearMemory();
			m_array = src.m_array;
			src.setEmpty();
		}
		return *this;
	}	

	size_t RecordSet::size() const
	{
		return m_countRecords;
	}

	std::string RecordSet::getRecord(size_t ind)
	{				
		if (ind >= m_countRecords)
			return string();
			else
			return m_array[ind];
	}

	RecordSet::~RecordSet()
	{
		clearMemory();
	}
}