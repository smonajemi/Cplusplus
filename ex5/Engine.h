/*
	Sina Monajemi
	021-324-124
	smonajemi@myseneca.ca
	OOP244-NBB
	Feb 20, 2020
*/
#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H

namespace sdds
{
	const int ENGINETYPE_SIZE = 30;

	class Engine
	{
		char m_engine_type[ENGINETYPE_SIZE + 1];
		double m_engine_size;

	public:
		Engine();
		Engine(const char*, double);
		
		//void setEngine(const Engine);
	    void setEmpty();
		void display() const;
		double getSize() const;
	};

}
#endif // !SDDS_ENGINE_H
