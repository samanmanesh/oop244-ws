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

		std::ostream& write(std::ostream& os)const;

		std::istream& read(std::istream& in);
	};

	std::ostream& operator<<(std::ostream& ostr, const Dumper& RO);

	std::istream& operator>>(std::istream& istr, Dumper& RO);
}
#endif
