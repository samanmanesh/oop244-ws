/*
Name:
Email:
Student ID:
Data:
Section:
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "VehicleBasic.h"
using namespace sdds;
using namespace std;

namespace sdds
{

	VehicleBasic::VehicleBasic(const char* licensePlateNo, int builtYear) :m_currentAddress("Factory")
	{
		strcpy(m_licensePlateNo, licensePlateNo);
		m_builtYear = builtYear;

	}
	VehicleBasic::~VehicleBasic()
	{
	}

	void VehicleBasic::NewAddress(const char* address) {

		if (!strcmp(m_currentAddress, address)) {

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
			cout << address << endl;
			cout.unsetf(ios::left);

			//not sure if should remove the old address or not check if works both way
			m_currentAddress[0] = '\0';
			strcpy(m_currentAddress, address);
		}
	}


	ostream& VehicleBasic::write(ostream& os) const{

		os << "| " << m_builtYear << " | " << m_licensePlateNo << " | " << m_currentAddress << endl;
		return os;
	};

	istream& VehicleBasic::read(istream& in) {
		
		in >> m_builtYear;
		in.getline(m_licensePlateNo, 10);
		in.getline(m_currentAddress, 22);

	}

	ostream& operator<<(ostream& ostr, const VehicleBasic& RO) {
		return (RO.write(ostr));
	};

	istream& operator>>(istream& istr, VehicleBasic& RO) {
		return (RO.read(istr));
	}
}
