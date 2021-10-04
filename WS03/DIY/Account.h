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


#ifndef SDDS_Account_H
#define SDDS_Account_H

namespace sdds {

	class Account {


		const double INTERESTRATE = 0.285;   //The Interest rate is always 28.5 % annually.
		const int INTERESTFREEPERIOUD = 30; // The Interest-free payment period is always 30 days.
		 

		int m_accountNumber;
		double m_balance;
		int m_days;

		void setEmpty();


	public:
		void set(const int accountNumber, double balance, int days);

		bool isEmpty() const;
  
		bool hasInterest() const;

		void display() const;

		double interest() const;

	};
}

#endif