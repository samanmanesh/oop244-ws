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


#include <iostream>
#include "Bus.h"
using namespace std;
using namespace sdds;

namespace sdds {

	Bus::Bus(int noOfSeats, int noOfPassengers) {

		if (((noOfSeats % 2) == 0) && noOfSeats >= 10 && noOfSeats <= 40 && noOfPassengers >= 0 && noOfPassengers <= noOfSeats) {

			m_noOfSeats = noOfSeats;
			m_noOfPassengers = noOfPassengers;

		}
		else
		{
			setOutOfService();
		}

	};


	void Bus::setOutOfService() {

		m_noOfSeats = -1;
		m_noOfPassengers = -1;
	}


	ostream& Bus::display(std::ostream& ostr) const {

		if (*this) {

			drawBus(ostr, m_noOfSeats, m_noOfPassengers);

			cout.setf(ios::fixed);
			cout.precision(2);
			cout << "Total Fare Price: " << double(*this) << endl;
			cout.unsetf(ios::fixed);

		}
		else
		{
			cout << "Out of service!" << endl;
		}

		return ostr;
	};


	void Bus::drawBus(ostream& ostr, int seats, int psng) const {

		// draws a bus with 
		// seat = number of seats
		// psng = number of passengers
		// on ostream

		int i, p;
		ostr.fill('_');
		ostr.width((seats / 2) * 3 + 4);
		ostr << "_";
		ostr << endl << "| ";
		for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < psng ? '2' : ((p == psng) ? '1' : ' ')) << "]");
		ostr << "|_\\_" << endl;
		ostr << "| ";
		ostr.fill(' ');
		ostr.width(((seats / 2) * 3 - 14) / 2);
		ostr << " " << "Seneca College";
		ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
		ostr << " " << "    )" << endl;
		ostr << "`---OO";
		ostr.fill('-');
		ostr.width((seats / 2) * 3 - 5);
		ostr << "-" << "O---'" << endl;
	}


	istream& Bus::read(std::istream& istr) {
		int noOfSeats;
		int noOfPsng;
		cin >> noOfSeats;
		cin.ignore();
		cin >> noOfPsng;

		Bus tempBus(noOfSeats, noOfPsng);

		if (noOfSeats % 2 == 0 && noOfSeats >= 10 && noOfSeats <= 40 && noOfPsng >= 0 && noOfPsng <= noOfSeats) {
			*this = tempBus;
		}
		else {
			setOutOfService();
		}
		return istr;
	}



	Bus::operator bool() const {
		return m_noOfSeats > 0;
	}


	Bus::operator int() const {
		int result = -1;

		if (*this) {
			result = m_noOfPassengers;
		}
		return result;
	}


	Bus::operator double() const {

		double result = -1.0;

		if (*this) {

			result = m_noOfPassengers * BusTicketPrice;

		}
		return result;
	}


	bool Bus::operator--() {
		bool result = false;

		if ((*this) && m_noOfPassengers > 0) {

			m_noOfPassengers--;
			result = true;
		}
		return result;
	}

	bool Bus::operator++() {
		bool result = false;

		if ((*this) && m_noOfPassengers < m_noOfSeats) {
			m_noOfPassengers++;
			result = true;
		}
		return result;
	}

	bool Bus::operator--(int) {
		return --(*this);
	}

	bool Bus::operator++(int) {
		return ++(*this);
	}


	Bus& Bus::operator=(int value) {

		m_noOfPassengers = value;

		if (m_noOfPassengers > m_noOfSeats) {

			setOutOfService();
		}
		return *this;
	}


	Bus& Bus::operator+=(int value) {
		if ((*this)) {
			m_noOfPassengers += value;
			if (m_noOfPassengers > m_noOfSeats) {
				setOutOfService();
			}
		}
		return *this;
	}

	Bus& Bus::operator+=(Bus& RO) {

		if ((*this) && (RO)) {

			m_noOfPassengers += RO.m_noOfPassengers;

			if (m_noOfPassengers > m_noOfSeats)
			{
				RO.m_noOfPassengers = m_noOfPassengers - m_noOfSeats;
				m_noOfPassengers = m_noOfSeats;
			}
		}
		return *this;
	}


	bool Bus::operator==(const Bus& RO) const {

		bool result = false;

		if ((*this) && (RO) && m_noOfPassengers == int(RO)) {

			result = true;
		}
		return result;
	}



	int operator+(int left, const Bus& right) {

		int result = left;

		if (right) {

			result += int(right);
		}
		return result;
	}

	ostream& operator<<(ostream& ostr, const Bus& right) {

		right.display(ostr);

		return ostr;
	}

	istream& operator>>(istream& istr, Bus& right) {

		right.read(istr);

		return istr;
	}

};