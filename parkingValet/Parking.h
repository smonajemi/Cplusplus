/*
File: MILESTONE 6

Name: SINA MONAJEMI
Email: smonajemi@myseneca.ca
Student Number: 021-324-124

Date: April 12, 2020 */

#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H
#include "Menu.h"
#include "Vehicle.h"

namespace sdds
{
	// The maximum number of parking spot
	const int MAX_NUMPARKING_SPOTS = 100;
	class Parking : public Menu
	{
		// Filename and Parking & Vehicle Menu:
		char* m_filename = nullptr;
		Menu m_Parking; //= "Parking Menu, select an action:";
		Menu m_Vehicle; //= "Select type of the vehicle:";
		
		// Newly added Member Variables -> MS6
		int m_noOfSpots = 0;
		int m_noOfParkedVehicles = 0;
		//array of VEhicle pointers -> Parking spot in the Parking!
		Vehicle* array[MAX_NUMPARKING_SPOTS]{};
			
		// I need to add setfunction for the above

	public:
		// constructor & destructor:
		Parking() {};
		Parking(const char*, int);
		~Parking();
		Parking(const Parking&) = delete;		
		int run();

	protected:

		Parking& operator=(const Parking& src) = delete;

		void clearMemory();
		void setEmptyState();
		void setName(const char*);	
		void populateParkingMenu();
		void populateVehicleMenu();		
		void ParkVehicle();
		void parkingStatus() const;
		void Parkinglist() const;
		void returnVehicle();		
		void saveData();

		bool checkValidation(int, int);
		int NumOfParkedVehicles();
		void setEmptyNewVariables();
	
		bool loadData();
		bool isEmpty() const;
		bool closeParking();		
		bool exitProgram();			
	};
}
#endif // !SDDS_PARKING_H
