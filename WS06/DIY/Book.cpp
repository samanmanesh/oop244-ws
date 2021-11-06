// ===================================================================================
//  Workshop: #6
//  Part: 2 (DIY)
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Date          : 2020-10-27
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
		else result = false;
		return result;

	};

	void Book::setEmpty() {
		m_authorName = nullptr;
		m_bookTitle = nullptr;
		m_bookCaseNum = 0;
		m_shelfNum = 0;
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

		if (bool(bookToBeCopied)) 
		{
			set(bookToBeCopied.m_bookTitle, bookToBeCopied.m_authorName, bookToBeCopied.m_bookCaseNum, bookToBeCopied.m_shelfNum);
		}
		else
		{
			setEmpty();
		}

	};


	Book::~Book() {

		delete[] m_authorName;
		delete[] m_bookTitle;

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
		return  (m_bookTitle != nullptr && m_authorName != nullptr && m_bookTitle[0] != 0 && m_authorName[0] != 0);
	};

	ostream& Book::write(ostream& ostr, bool onScreen)const {


		if (*this) {
			if (onScreen) {

				ostr.width(40);
				ostr.setf(ios::left);
				ostr << m_bookTitle;
				ostr.unsetf(ios::left);

				ostr << "| ";

				ostr.setf(ios::left);
				ostr.width(25);
				ostr << m_authorName;
				ostr.unsetf(ios::left);

				ostr << "| ";

				ostr << m_shelfNum << "/";
				ostr.setf(ios::right);
				ostr.fill('0');
				ostr.width(3);
				ostr << m_bookCaseNum;

				ostr.fill(' ');
				ostr.unsetf(ios::right);

			}
			else
			{
				ostr << m_bookTitle << "," << m_authorName << "," << m_shelfNum << "/" << m_bookCaseNum;
			}


		}
		else
		{
			ostr.width(40);
			ostr.setf(ios::left);
			ostr.fill('.');
			ostr << "Invalid Book Record ";
			ostr.unsetf(ios::left);
			ostr << "| ";

			ostr.width(27);
			ostr << "| ";
			ostr.setf(ios::left);
			ostr.width(5);
			ostr << ".";
			ostr.unsetf(ios::right);
			ostr.fill(' ');

		}
		return ostr;
	};



	void Book::extractChar(std::istream& istr, char ch)const {


		if (istr.peek() == ch) {
			istr.get();
		}
		else
		{
			istr.setstate(ios::failbit);
		}

	};

	istream& Book::read(istream& istr) {
		char bookTitle[MaxTitleLen + 1]; 
		

		char authorName[MaxAuthorLen + 1]; 
		int shelfNum = 0; 
		int bookCaseNum = 0; 

		istr.getline(bookTitle, MaxTitleLen + 1 , ',');
		istr.getline(authorName, MaxAuthorLen + 1, ',');
		istr >> shelfNum;
		if (shelfNum < 1 || shelfNum > NoOfShelves) {
			istr.setstate(ios::failbit);
		}
		extractChar(istr, '/');

		istr >> bookCaseNum;
		if (bookCaseNum < 1 || bookCaseNum > NoOfBookCases) {
			istr.setstate(ios::failbit);
		}
		

		if (!istr.fail()) 
		{
			set(bookTitle, authorName, bookCaseNum, shelfNum);
		}
		return istr;
	};





	ostream& operator<<(ostream& ostr, const Book& RO) {

		return (RO.write(ostr, true));

		
	};

	istream& operator>>(istream& istr, Book& RO) {
		return (RO.read(istr));
	}
}


