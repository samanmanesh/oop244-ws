
// ===================================================================================
//  Workshop: #3
//  Part: 1 (Lab)
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Date          : 2020-09-29
//  Course Section: OOP244-NAA
// ===================================================================================
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
// ===================================================================================


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"
using namespace std;
using namespace sdds;

namespace sdds {

	void Book::set(const char titleOfBook[], int SKU, int daysOnLoan) {
		if (titleOfBook[0] != '\0' && SKU > 0 && daysOnLoan > 0) {

			strcpy(m_title, titleOfBook);
			m_SKU = SKU;
			m_daysOnLoan = daysOnLoan;
		}
		else
		{
			setEmpty();
		}
	}

	bool Book::isEmpty() const {
		return (m_title[0] == '\0' && m_SKU == 0 && m_daysOnLoan == 0);
	};

	bool Book::hasPenalty() const {
		return (m_daysOnLoan > MAXLOAN);
	};

	bool Book::subTitle(const char subString[]) {
		bool result;
		if (strstr(m_title, subString)) {
			result = true;

		}
		else {
			result = false;
		}
		return result;
	};

	void Book::display() const {
		
		if (!isEmpty()) {

			cout.width(49);
			cout.setf(ios::left);
			cout << m_title;
			cout.unsetf(ios::left);

			cout.width(8);
			cout.setf(ios::left);
			cout << m_SKU;
			cout.unsetf(ios::left);

			cout.width(10);
			cout.setf(ios::left);
			cout << m_daysOnLoan;
			cout.unsetf(ios::left);

			if (hasPenalty()) {
				cout.width(7);
				cout.setf(ios::fixed);
				cout.precision(2);
				cout << penalty();
				cout.unsetf(ios::fixed);
			}
			cout << endl;
		}
		else {
			cout << "Invalid library book" << endl;
		}

	};

	void Book::setEmpty() {

		m_title[0] = '\0';
		m_SKU = 0;
		m_daysOnLoan = 0;

	};

	double Book::penalty() const {
		double overDueDays;
		double penalty;
		overDueDays = m_daysOnLoan - MAXLOAN;
		penalty = overDueDays * PENALTY;
		return penalty;
	};

}