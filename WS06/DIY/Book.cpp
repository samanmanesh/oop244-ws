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


	Book::Book(const Book& bookToBeCopied) {

		if (bookToBeCopied.m_authorName && bookToBeCopied.m_bookTitle)
		{
			set(bookToBeCopied.m_bookTitle, bookToBeCopied.m_authorName, bookToBeCopied.m_bookCaseNum, bookToBeCopied.m_shelfNum);
		}
		else
		{
			setEmpty();
		}

	};

	Book& Book::operator=(const Book& bookToBeCopied) {

		if (this != &bookToBeCopied)
		{
			set(bookToBeCopied.m_bookTitle, bookToBeCopied.m_authorName, bookToBeCopied.m_bookCaseNum, bookToBeCopied.m_shelfNum);
		}
		return *this;
	};




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


	Book::operator bool() const {
		return  (m_bookTitle != nullptr && m_authorName != nullptr);
	};

	ostream& Book::write(ostream& ostr, bool onScreen)const {

		if (onScreen)
		{
			if (*this) {

				ostr.width(45);
				ostr.setf(ios::left);
				ostr << m_bookTitle;
				ostr.setf(ios::right);
				ostr << "| ";
				ostr.setf(ios::left);
				ostr.width(25);
				ostr << m_authorName;
				ostr.setf(ios::right);
				ostr << "| ";
				ostr << m_shelfNum << "/";
				ostr.fill('0');
				ostr.width(3);
				ostr<< m_bookCaseNum;
				ostr.fill(' ');
			}
			else
			{
				ostr.width(40);
				ostr.setf(ios::left);
				ostr.fill('.');
				ostr << "Invalid Book Record ";
				ostr.setf(ios::right);
				ostr << "| ";
				ostr.width(28);
				ostr << "| ";
			}
		}
		else
		{
			if (*this)
			{
				ostr << m_bookTitle << "," << m_authorName << "," << m_shelfNum << "/" << m_bookCaseNum;
			}
			else
			{
				ostr << "Invalid Book Record";
			}

		}

		return ostr;
	};



	void Book::extractChar(std::istream& istr, char ch)const {

		if (istr.peek() == ch ) {
			istr.get();
		}
		else
		{
			istr.setstate(ios::failbit);
		}

	};

	istream& Book::read(istream& istr) {

		char bookTitle[128];
		char authorName[128];
		int shelfNum;
		int bookCaseNum;
		
		istr.getline(bookTitle, MaxTitleLen, ',');
		extractChar(istr, ',');
		istr.getline(authorName, MaxAuthorLen, ',');
		extractChar(istr, ',');
		istr>> shelfNum;
		extractChar(istr, '/');
		istr >> bookCaseNum;
		extractChar(istr, '\n');

		if (shelfNum > NoOfShelves || shelfNum < 0 || bookCaseNum > NoOfBookCases || bookCaseNum < 0)
		{
			istr.setstate(ios::failbit);
		}

		if (!istr.fail())
		{
			set(bookTitle, authorName, shelfNum, bookCaseNum);
		}
		return istr;
	};





	ostream& operator<<(ostream& ostr, const Book& RO) {

		if (RO) {
			
				RO.write(ostr, true);
		}
		else
		{
			ostr << "Invalid Book Record";
		}
		return ostr;
	};
	
	istream& operator>>(istream& istr, Book& RO) {
		return (RO.read(istr));
	}
}


