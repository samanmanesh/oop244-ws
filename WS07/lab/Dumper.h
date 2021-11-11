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

		bool unloadCargo();
	};

	

	Dumper::~Dumper()
	{
	}


}
#endif
