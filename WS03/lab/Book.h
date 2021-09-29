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

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

namespace sdds {

	class Book
	{
	private:
		const double PENALTY = 1.5; // Penalty in dollars for each day a book's return is overdue
		const int MAXLOAN = 15; // Maximum number of days to loan a book witout penalty.

		char m_title[50 + 1];
		int m_SKU;
		int m_daysOnLoan;

		void setEmpty();
		double penalty()const;

	public:
		void set(const char titleOfBook[], int SKU, int daysOnLoan);
		
		bool isEmpty ()const;
		
		bool hasPenalty()const;

		bool subTitle(const char subString[]);

		void display()const;
	};

	



}

#endif