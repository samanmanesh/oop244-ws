// ===================================================================================
//  Workshop: #3
//  Part: 1 (Lab)
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Date          : 2020-09-30
//  Course Section: OOP244-NAA
// ===================================================================================
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
// ===================================================================================

#ifndef SDDS_LIBRARY_H
#define SDDS_LIBRARY_H
#include"Book.h"
namespace sdds {

	class Library {

		char m_name[30 + 1];
		Book* m_books;
		int m_sizeOfBooksArray;
		int m_addedBooks;

		void setEmpty();
		bool isEmpty()const;
		void header(const char* title)const;
		void footer()const;

	public:
		void initialize(const char* name, int noOfBooks);

		bool addBook(const char* book_title, int sku, int loanDays);

		void clear();

		void display(const char* substr);

		void display(bool overdueOnly = false)const;

	};

}

#endif