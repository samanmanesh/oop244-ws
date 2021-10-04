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
#include "Bank.h"
using namespace std;
using namespace sdds;


#include"Bank.h"
namespace sdds {



	void Bank::setEmpty() {

		m_bankName[0] = '\0';
		m_account = nullptr;
		m_numOfAccounts = 0;
		m_addedAccount = 0;
	}


	bool Bank::isEmpty() const {
		return (m_bankName[0] == '\0');
	}


	void Bank::header() const {
		cout << "----------------------------------------" << endl;
		cout << ">>> " << m_bankName << " <<<" << endl;
		cout << "----------------------------------------" << endl;
		cout << "Row Accnt No       Balance  Days Interest" << endl;
		cout << "--- ---------- ------------ ---- --------" << endl;
	}


	void Bank::footer()const {
		cout << "-----------------------------------------" << endl;
	}

	void Bank::initialize(const char* bankName, int numAccounts) {
	
		if (bankName != NULL && bankName[0] != '\0' && numAccounts > 0) {
			strcpy(m_bankName, bankName);
			m_numOfAccounts = numAccounts;
			m_account = nullptr;
			m_account = new Account[numAccounts];
			m_addedAccount = 0;
		}
		else
		{
			setEmpty();
		}
	}



	bool Bank::addAccount(int accountNumber, double balance, int numberOfDaysSinceLastPay) {
		bool result = false;

		if (m_addedAccount < m_numOfAccounts) {

			m_account[m_addedAccount].set(accountNumber, balance, numberOfDaysSinceLastPay);
			
			if (!m_account[m_addedAccount].isEmpty() ) {
				m_addedAccount++;
				result = true;
			}

		}
		return result;
	}

	void Bank::clear() {
		delete[] m_account;
		m_account = nullptr;

	}
	void Bank::display(bool interestOnly)const {
		if (!isEmpty()) {
			int rowNumber = 1;
			double totalInterest = 0;
			if (interestOnly) {
				cout << "INTEREST ONLY LIST!" << endl;
			}
			header();
			for (int i = 0; i < m_addedAccount; i++) {

				if (interestOnly) {

					if (m_account[i].hasInterest()) {
						cout.width(5);
						cout.setf(ios::left);
						cout << rowNumber;
						rowNumber++;
						totalInterest += m_account[i].interest();
						m_account[i].display();
					}

				}
				else {

					cout.width(5);
					cout.setf(ios::left);
					cout << rowNumber;
					rowNumber++;
					m_account[i].display();

					if (m_account[i].hasInterest()) {
						totalInterest += m_account[i].interest();
					}

				}

			}

			footer();
			cout.width(29);
			cout.setf(ios::right);
			cout << "Total interest:";
			cout.width(12);
			cout << totalInterest << endl << endl;
			cout.unsetf(ios::right);
		}
		else {
			cout << "Invalid Bank" << endl;
		}

	}





}

