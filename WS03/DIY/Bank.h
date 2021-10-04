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

#ifndef SDDS_BANK_H
#define SDDS_BANK_H
#include "Account.h"
namespace sdds {

	class Bank {
		
		char m_bankName[50 + 1];
		
		Account* m_account;
		
		int m_numOfAccounts;
		
		int m_addedAccount;

		
		void setEmpty();
		
		bool isEmpty()const;
		
		void header()const;
		
		void footer()const;
	
	public:
		void initialize(const char* bankName, int numAccounts);
		
		bool addAccount(int accountNumber, double balance, int numberOfDaysSinceLastPay);
		
		void clear();
		
		void display(bool intrestOnly = false)const;

	};

}

#endif