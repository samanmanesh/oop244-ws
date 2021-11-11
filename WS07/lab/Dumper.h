/*
Name:
Email:
Student ID:
Data:
Section:
*/
#ifndef SDDS_Dumper_H
#define SDDS_Dumper_H
#include <iostream>
#include "VehicleBasic.h"

namespace sdds
{

	class Dumper : public VehicleBasic
	{
		double m_maxWeightCargo;
		double m_currentCargo;

	public:
		Dumper(const char* licensePlateNo, int builtYear, double dumberCapacity, const char* currentAddress);
		~Dumper();

		bool loaddCargo(double cargo);
	};

	bool Dumper::loaddCargo(double cargo) {
		
		bool result = false;
		if (cargo + m_currentCargo < m_maxWeightCargo) {
			
			m_currentCargo + cargo;
			result = true;
		}
		return result;
	};

	Dumper::~Dumper()
	{
	}


}
#endif
