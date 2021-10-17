// ===================================================================================
//  Workshop: #5
//  Part: 2 (DIY)
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Date          : 2020-10-17
//  Course Section: OOP244-NAA
// ===================================================================================
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
// ===================================================================================


#ifndef SDDS_BUS_H
#define SDDS_BUS_H
#include <iostream>
namespace sdds {

	const double BusTicketPrice = 125.34;

	class Bus {
		int m_noOfSeats;
		int m_noOfPassengers;

		void setOutOfService();

		void drawBus(std::ostream& ostr, int seats, int psng) const;

	public:

		Bus(int noOfSeats = 20, int noOfPassengers = 0);

		std::ostream& display(std::ostream& ostr = std::cout) const;
		
		std::istream& read(std::istream& istr = std::cin);

		operator bool() const;
		operator int() const;
		operator double() const;

		bool operator--();
		bool operator++();
		bool operator--(int);
		bool operator++(int);


		Bus& operator=(int value);

		Bus& operator+=(int value);

		Bus& operator+=(Bus& RO);

		bool operator==(const Bus& RO) const;

	};


	int operator+(int left, const Bus& right);

	std::ostream& operator<<(std::ostream& ostr, const Bus& right);

	std::istream& operator>>(std::istream& istr, Bus& right);

}
#endif