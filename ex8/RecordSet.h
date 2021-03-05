/*
	Name: SINA MONAJEMI
	Student#: 021-324-124
	E-mail: smonajemi@myseneca.ca
	OOP 345 - DIY 2
*/
#include <iostream>

#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H

namespace sdds
{	
	class RecordSet
	{		
		std::string* m_array = nullptr;	
		size_t m_countRecords = 0;

		void setEmpty(); // set the member variables to empty
		void clearMemory(); // delete data
		void readFile(const char*); // read file

	public:

		RecordSet(){}; // default constructor
		RecordSet(const char*); // 1 arg constructor
		RecordSet(const RecordSet&); // copy constructor
		RecordSet& operator=(const RecordSet&); // assignment operator
		RecordSet(RecordSet&&); // Move constructor
		RecordSet& operator=(RecordSet&&); // Move assignment operator
		size_t size() const; // quesry to return the size
		std::string getRecord(size_t); // query to return the index of the array
		~RecordSet(); // destructor
	};
}
#endif // !SDDS_RECORDSET_H
