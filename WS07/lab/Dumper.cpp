/*
Name:
Email:
Student ID:
Data:
Section:
*/
#include<iostream>
#include "Dumper.h"
#include "VehicleBasic.h"

namespace sdds
{
	Dumper::Dumper(const char* licensePlateNo, int builtYear, double dumberCapacity, const char* currentAddress) :VehicleBasic(licensePlateNo, builtYear)
	{
		m_maxWeightCargo = dumberCapacity;
		m_currentCargo = 0;
		NewAddress(currentAddress);
	}


	
	
	
}
