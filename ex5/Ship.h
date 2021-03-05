/*
    Sina Monajemi
    021-324-124
    smonajemi@myseneca.ca
    OOP244-NBB
    Feb 20, 2020
*/
#ifndef SDDS_SHIPS_H
#define SDDS_SHIP_H
#include "Engine.h"

namespace sdds
{
    const int SHIPTYPE_SIZE = 6;
    const int FIXED_SIZE = 10;

    class Ship
    {
        
        Engine* m_engine;
        char* m_ship_type;
        int m_num;        
        float m_distance;

        void setEmpty();

    public:
        Ship();
        ~Ship();
        Ship(const char*,const Engine* engine, int);

        void clearMemory();
        void display() const;
       
        bool empty() const;
        float calculatePower() const;       
        Ship& operator+=(const Engine& e);

      };
    bool operator==(const Ship&, const Ship&);
    bool operator<(const Ship&, double);
}
#endif // !SDDS_SHIPS_H
