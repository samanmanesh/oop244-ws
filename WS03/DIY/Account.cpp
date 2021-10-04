// ===================================================================================
//  Workshop: #3
//  Part: 2 (DIY)
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Date          : 2020-10-1
//  Course Section: OOP244-NAA
// ===================================================================================
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
// ===================================================================================



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Account.h"
using namespace std;
using namespace sdds;

namespace sdds {


	void Account:: set(const int accountNumber, double balance, int days) {
		if (accountNumber > 0) {
			m_accountNumber = accountNumber;
			m_balance = balance;
			m_days = days;

		}
		else
		{
			setEmpty();
		}
	}


	void Account::setEmpty() {
		m_accountNumber = 0;
		m_balance = 0;
		m_days = 0;

	}

	bool Account::isEmpty() const {
		return (m_accountNumber == 0);
	}


	bool Account::hasInterest() const {
		return (m_days > INTERESTFREEPERIOUD);
	}


	void Account::display() const {
		if (!isEmpty()) {
			cout.width(11);
			cout.setf(ios::left);
			cout << m_accountNumber;
			cout.width(11);
			cout.unsetf(ios::left);
			cout.setf(ios::right);
			std::cout << std::fixed;
			cout.precision(2);
			cout << m_balance;
			cout << "  ";
			cout.width(4);
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout << m_days;
			if (hasInterest()) {
				cout.width(8);
				cout.unsetf(ios::left);
				cout.setf(ios::right);
				std::cout << std::fixed;
				cout.precision(2);
				cout << interest();
				cout.unsetf(ios::right);
			}
			cout << endl;
		}
		else {
			cout << "Invalid account";
		}

	}
	
	double Account::interest() const {
		return m_days * (INTERESTRATE / 365) * m_balance;
	}

};

