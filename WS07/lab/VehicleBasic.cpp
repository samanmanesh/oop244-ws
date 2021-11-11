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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "VehicleBasic.h"
using namespace sdds;
using namespace std;

namespace sdds
{

	VehicleBasic::VehicleBasic(const char* licensePlateNo, int builtYear) 
	{	
		strcpy(m_currentAddress,"Factory" );
		strcpy(m_licensePlateNo, licensePlateNo);
		m_builtYear = builtYear;

	}
	VehicleBasic::~VehicleBasic()
	{
	}

	void VehicleBasic::NewAddress(const char* address) {

		if (strcmp(m_currentAddress, address)) {

			cout << "|";
			cout.setf(ios::right);
			cout.width(8);
			cout << m_licensePlateNo;
			cout.unsetf(ios::right);
			cout << "| " << "|";
			cout.setf(ios::right);
			cout.width(20);
			cout << m_currentAddress;
			cout.unsetf(ios::right);
			cout << " ---> ";
			cout.width(20);
			cout.setf(ios::left);
			cout << address << "|";
			cout << endl;
			cout.unsetf(ios::left);

			strcpy(m_currentAddress, address);
		}
	}


	ostream& VehicleBasic::write(ostream& os) const {

		os << "| " << m_builtYear << " | " << m_licensePlateNo << " | " << m_currentAddress;
		return os;
	};

	istream& VehicleBasic::read(istream& in) {

		cout << "Built year: ";
		in >> m_builtYear;
		cout << "License plate: ";
		in >> m_licensePlateNo;
		cout << "Current location: ";
		in >> m_currentAddress;
		return in;
	}

	ostream& operator<<(ostream& ostr, const VehicleBasic& RO) {
		return (RO.write(ostr));
	};

	istream& operator>>(istream& istr, VehicleBasic& RO) {
		return (RO.read(istr));
	}
}
