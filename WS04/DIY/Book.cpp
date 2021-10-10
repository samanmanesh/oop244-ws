#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"
using namespace std;
using namespace sdds;

namespace sdds {

	Book::Book() {
		setEmpty();
	};

	Book::Book(const char* bookName, int noOfChapter, const Chapter* chapters) {

		setEmpty();
		bool chaptersIsSafe = true;

		if (bookName != nullptr && bookName[0] != 0 && noOfChapter > 0 && chapters != nullptr)
		{
			for (int i = 0; i < noOfChapter; i++)
			{
				if (chapters[i].isEmpty()) {
					chaptersIsSafe = false;
				}
			}
				
			if (chaptersIsSafe == true)
				{

					setBookName(bookName);
					m_noOfChapter = noOfChapter;

					m_chapter = new Chapter[m_noOfChapter];

					for (int i = 0; i < m_noOfChapter; i++)
					{
						m_chapter[i] = chapters[i];
					}
			}
			
		}
	};

	void Book::setEmpty() {
		m_bookName = nullptr;
		m_chapter = nullptr;
		m_noOfChapter = 0;
	};

	void Book::setBookName(const char* bookName) {
		delete m_bookName;
		m_bookName = nullptr;

		if (bookName != nullptr && bookName[0] != 0)
		{
			char* newBookName = nullptr;
			newBookName = new char[strlen(bookName) + 1];
			strcpy(newBookName, bookName);
			m_bookName = newBookName;
			newBookName = nullptr;

		}
		else
		{
			delete[] m_chapter;
			setEmpty();
		}


	};


	/*Country& Country::addCity(const City& c) {

		if (!c.isEmpty()) {
			City* newCity = nullptr;
			newCity = new City[m_noOfCity + 1];

			for (int i = 0; i < m_noOfCity; i++)
			{
				newCity[i] = m_city[i];
			}

			delete[] m_city;
			newCity[m_noOfCity] = c;
			m_noOfCity++;
			m_city = newCity;
			newCity = nullptr;

		}
		return *this;
	};*/

	Book& Book::addChapter(const char* chapter_name, int noOfPages) {

		if (chapter_name != nullptr && chapter_name[0] != 0 && noOfPages > 0 ) {

			Chapter* newChapter = nullptr;
			newChapter = new Chapter[m_noOfChapter + 1];

			for (int i = 0; i < m_noOfChapter; i++)
			{
				newChapter[i] = m_chapter[i];
			
			}

			delete[] m_chapter;
			newChapter[m_noOfChapter ].setChapterName(chapter_name);
			newChapter[m_noOfChapter ].setPages(noOfPages);
			m_noOfChapter++;
			m_chapter = newChapter;
			newChapter = nullptr;

		}
		return *this;
	};


	bool Book::isEmpty()const {
		//jif it doesnt work it needs just m_bookName to be checked for Book state
		return (
			m_bookName == nullptr ||
			m_chapter == nullptr ||
			m_noOfChapter == 0);
	};

	

	/*void Country::display()const {

		if (!isEmpty()) {

			cout << "Country Name: " << m_name << endl;
			cout << "No of city: " << m_noOfCity << endl;
			cout.width(32);
			cout.setf(ios::left);
			cout << "City name";
			cout.unsetf(ios::left);
			cout << "Population" << endl;
			for (int i = 0; i < m_noOfCity; i++)
			{
				m_city[i].display();
			}
		}
		else
		{
			cout << "Invalid country object" << endl;
		}

	};*/
		
	void Book::display() const {
	
		if (!isEmpty()) {
		
			cout << "Book Name: ";
			cout << m_bookName << endl;
			cout << "No of chapters: ";
			
			cout << m_noOfChapter << endl;
			cout << "Chapter name";
			cout.width(44);
			cout << "Pages" << endl;


			for (int i = 0; i < m_noOfChapter; i++)
			{
				m_chapter[i].display();
			}


		}
		else
		{
			cout << "Invalid book object" << endl;
		}
	
	};

	Book::~Book() {
		delete m_bookName;
		delete[] m_chapter;
	};


}