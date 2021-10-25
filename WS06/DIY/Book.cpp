// ===================================================================================
//  Workshop: #6
//  Part: 2 (DIY)
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Date          : 2020-10-24
//  Course Section: OOP244-NAA
// ===================================================================================
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
// ===================================================================================

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"
using namespace std;
using namespace sdds;
namespace sdds {

	bool Book::validBook(const char* bookTitle, const char* authorName, int bookCaseNum, int shelfNum)const {

		bool result = false;

		if (bookTitle != nullptr && bookTitle[0] != 0 && authorName != nullptr && authorName[0] != 0 &&
			bookCaseNum >= 1 && bookCaseNum <= NoOfBookCases &&
			shelfNum >= 1 && shelfNum <= NoOfShelves)
		{
			result = true;

		}
		else
			result = false;
		return result;

	};

	void Book::setEmpty() {
		m_authorName = nullptr;
		m_bookTitle = nullptr;
	};

	Book::Book() {
		setEmpty();
		m_bookCaseNum = 0;
		m_shelfNum = 0;
	};

	Book::Book(const char* bookTitle, const char* authorName, int bookCaseNum, int shelfNum) {

		set(bookTitle, authorName, bookCaseNum, shelfNum);
	}





	void Book::set(const char* bookTitle, const char* authorName, int bookCaseNum, int shelfNum) {

		if (validBook(bookTitle, authorName, bookCaseNum, shelfNum)) {
			allocateAndCopy(bookTitle, authorName);
			m_bookCaseNum = bookCaseNum;
			m_shelfNum = shelfNum;
		}
		else
		{
			delete[] m_bookTitle;
			delete[] m_authorName;
			setEmpty();
		}


	}


	void Book::allocateAndCopy(const char* bookTitle, const char* authorName) {

		delete[] m_bookTitle;
		delete[] m_authorName;

		if (authorName != nullptr && authorName[0] != 0 && bookTitle != nullptr && bookTitle[0] != 0)
		{
			m_bookTitle = new char[strlen(bookTitle) + 1];
			m_authorName = new char[strlen(authorName) + 1];

			strcpy(m_bookTitle, bookTitle);
			strcpy(m_authorName, authorName);
		}
	};



}

