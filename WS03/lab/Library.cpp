
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
		
		return(m_name[0] == 0 && m_books == nullptr && m_sizeOfBooksArray == 0 && m_addedBooks == 0);
		
	};

	void Library::header(const char* title)const {
		cout.fill('-');
		cout.width(78);
		cout<<"-" << endl;
		cout.fill(' ');

		cout << "***** " << m_name << " *****" << endl;
		
		cout << title << endl;
		cout.fill('-');
		cout.width(78);
		cout <<"-" << endl;
		cout.fill(' ');
		cout << "Row Book title                                       SKU     loan days penalty"
			<< endl;
		cout << "--- ------------------------------------------------ ------- --------- -------"
			<< endl;
		cout.fill(' ');
	};

	void Library::footer()const {
		cout.fill('-');
		cout.width(78);
		cout << "-" << endl;
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

	bool Library::addBook(const char* book_title, int sku, int loanDays) {
		bool result;
		if (m_addedBooks < m_sizeOfBooksArray) {

			m_books[m_addedBooks].set(book_title, sku, loanDays);
			if (!m_books[m_addedBooks].isEmpty())
			{
				result = true;
				m_addedBooks++;
			}
			else
			{
				result = false;
			}

		}
		else
		{
			result = false;
		}
		return result;
	};

	void Library::clear() {

		delete[] m_books;
		m_books = nullptr;
	};

	void Library::display(const char* substr) {

		if (!isEmpty())
		{
			int rowNumber = 1;
			bool searchFlag = false;
			cout << ">>> Searching for: \"";
			cout << substr;
			cout << "\" <<<" << endl;
			header("Substring search");
			for (int i = 0; i < m_addedBooks; i++)
			{
				if (m_books[i].subTitle(substr)) {
					cout.width(4);
					cout.setf(ios::left);
					cout << rowNumber;
					cout.unsetf(ios::left);
					rowNumber++;
					m_books[i].display();
					searchFlag = true;
				}
			}
			if (!searchFlag)
			{
				cout << "No book title contains \"";
				cout << substr;
				cout << "\"" << endl;
			}
			footer();
		}
		else {
			cout << "Invalid Library" << endl;
		}

	};
	void Library::display(bool overdueOnly)const {

		if (!isEmpty()) {
			int rowNumber = 1;
			

			if (overdueOnly == true)
			{
				header("Overdue Books");
			}else if(overdueOnly == false) {

				header("Books on Loan");
			}

			for (int i = 0; i < m_addedBooks; i++)
			{
				if (overdueOnly == true)
				{
					if (m_books[i].hasPenalty()) {

						cout.width(4);
						cout.setf(ios::left);
						cout << rowNumber;
						rowNumber++;
						m_books[i].display();
					}
				}
				else if(overdueOnly == false)
				{	
					cout.width(4);
					cout.setf(ios::left);
					cout << rowNumber;
					cout.unsetf(ios::left);
					rowNumber++;
					m_books[i].display();

				}
			}
			footer();


		}
		else {
			cout << "Invalid Library" << endl;
		}
	};

};



