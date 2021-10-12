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

		if (!(bookName != nullptr && bookName[0] != 0 && noOfChapter >= 0 && chapters != nullptr))
		{
			return;
		}

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



	Book& Book::addChapter(const char* chapter_name, int noOfPages) {

		if (chapter_name != nullptr && chapter_name[0] != '\0' && noOfPages > 0 && noOfPages < MAXPAGES) {
			
			Chapter* newChapters = nullptr;
			newChapters = new Chapter[m_noOfChapter + 1];

			for (int i = 0; i < m_noOfChapter; i++)
			{
				newChapters[i] = m_chapter[i];
			}

			delete[] m_chapter;

			newChapters[m_noOfChapter].setChapterName(chapter_name);
			newChapters[m_noOfChapter].setPages(noOfPages);

			m_noOfChapter++;
			m_chapter = newChapters;			
			newChapters = nullptr;
			
		}
		return *this;
	};


	bool Book::isEmpty()const {

		return (
			m_bookName == nullptr ||
			m_chapter == nullptr ||
			m_noOfChapter == 0);
	};





	void Book::display() const {

		if (!isEmpty()) {

			cout << "Book Name: ";
			cout << m_bookName << endl;
			cout << "No of Chapters: ";

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
			cout << "Invalid Book object" << endl;
		}

	};

	Book::~Book() {
		delete m_bookName;
		delete[] m_chapter;
		
	};


}
