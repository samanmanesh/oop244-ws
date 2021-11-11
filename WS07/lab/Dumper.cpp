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
using namespace sdds;
using namespace std;
namespace sdds
{
	Dumper::Dumper(const char* licensePlateNo, int builtYear, double dumberCapacity, const char* currentAddress) :VehicleBasic(licensePlateNo, builtYear)
	{
		m_maxWeightCargo = dumberCapacity;
		m_currentCargo = 0;
		NewAddress(currentAddress);
	}

	bool Dumper::loaddCargo(double cargo) {

		bool result = false;
		if (cargo + m_currentCargo < m_maxWeightCargo) {

			m_currentCargo + cargo;
			result = true;
		}
		return result;
	};

	bool Dumper::unloadCargo() {
		bool result = false;
		if (m_currentCargo)
		{
			m_currentCargo = 0;
			result = true;
		}
		return result;
	}
	
	ostream& Dumper::write(ostream& os) {
		VehicleBasic::write(os);
		os << " | " << m_currentCargo << "/" << m_maxWeightCargo;
	};
	
}
