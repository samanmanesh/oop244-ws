// ===================================================================================
//  Workshop: #7
//  Part: 1 (Lab)
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Date          : 2021-11-11
//  Course Section: OOP244-NAA
// ===================================================================================
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
// ===================================================================================
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
	Dumper::~Dumper()
	{
	}

	bool Dumper::loaddCargo(double cargo) {

		bool result = false;
		if (cargo + m_currentCargo < m_maxWeightCargo) {

			m_currentCargo += cargo;
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
	
	ostream& Dumper::write(ostream& os) const{
		VehicleBasic::write(os);
		os << " | " << m_currentCargo << "/" << m_maxWeightCargo;
		
		return os;
	};
	
	istream& Dumper::read(istream& in) {

		VehicleBasic::read(in);
		cout << "Capacity: ";
		in >> m_maxWeightCargo;
		cout << "Cargo: ";
		in >> m_currentCargo;
		
		return in;
	}

	ostream& operator<<(ostream& ostr, const Dumper& RO) {
		return (RO.write(ostr));
	};

	istream& operator>>(istream& istr, Dumper& RO) {
		return (RO.read(istr));
	}
}
