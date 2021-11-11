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

	};

	Dumper::Dumper(const char* licensePlateNo, int builtYear, double dumberCapacity, const char* currentAddress) :VehicleBasic(licensePlateNo, builtYear)
	{
		m_maxWeightCargo = dumberCapacity;
		m_currentCargo = 0;
		VehicleBasic::NewAddress(currentAddress);
	}

	Dumper::~Dumper()
	{
	}


}
#endif
