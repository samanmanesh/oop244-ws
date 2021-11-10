/*
Name:
Email:
Student ID:
Data:
Section:
*/
#ifndef SDDS_VehicleBasic_H
#define SDDS_VehicleBasic_H
#include<iostream>
namespace sdds
{
	class VehicleBasic
	{
		char m_licensePlateNo[9];
		char m_currentAddress[21];
		int m_builtYear;

	public:
		VehicleBasic(const char* licensePlateNo, int builtYear);

		~VehicleBasic();

		void NewAddress(const char* address);

		std::ostream& write(std::ostream& os);
		
		std::istream& read(std::istream& in);
	};

	
	
	




	VehicleBasic::~VehicleBasic()
	{
	}

}

#endif