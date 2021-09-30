
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
#include "Library.h"
using namespace std;
using namespace sdds;

namespace sdds {

	void Library::setEmpty() {
		m_name[0] = '\0';
		m_books = nullptr;
		m_sizeOfBooksArray = 0;
		m_addedBooks = 0;
	}

	bool Library::isEmpty()const {

		return(m_name[0] != 0 && m_books != nullptr && m_sizeOfBooksArray != 0 && m_addedBooks != 0);
	};

	void Library::header(const char* title)const {
		cout.fill('-');
		cout.width(78);
		cout << endl;
		cout << "***** " << m_name << " *****" << endl;
		cout.fill(' ');
		cout << title << endl;
		cout.fill('-');
		cout.width(78);
		cout << endl;
		cout.fill(' ');
		cout << "Row Book title                                       SKU     loan days penalty"
			<< endl;
		cout << "--- ------------------------------------------------ ------- --------- -------"
			<< endl;
	};

	void Library::footer()const {
		cout.fill('-');
		cout.width(78);
		cout << endl;
		cout.fill(' ');
	};

	void Library::initialize(const char* name, int noOfBooks) {
		
		if (name != nullptr && name[0] != 0 && noOfBooks > 0) {

			strcpy(m_name, name);
			m_sizeOfBooksArray = noOfBooks;
			m_addedBooks = 0;
			m_books = new Book[noOfBooks];
		}
		else {
			setEmpty();
		}
	
	};


}
