// ===================================================================================
//  Workshop: #4
//  Part: 2 (DIY)
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Date          : 2020-10-10
//  Course Section: OOP244-NAA
// ===================================================================================
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
// ===================================================================================


#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include "Chapter.h"
namespace sdds {

	

	class Book
	{

		char* m_bookName;//points to a dynamically allocated Cstring holding the book name

		int m_noOfChapter;//size of the dynamically allocated array of chapter

		Chapter* m_chapter = nullptr;//pointer to the dynamically allocated array of chapter

		void setEmpty();

	public:

		Book();

		Book(const char* bookName, int noOfChapter, const Chapter* chapters);

		void setBookName(const char* bookName);

		Book& addChapter(const char* chapter_name, int noOfPages);

		bool isEmpty()const;

		void display()const;


		~Book();

	};

}

#endif