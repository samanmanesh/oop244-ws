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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Chapter.h"
using namespace std;
using namespace sdds;

namespace sdds {

	Chapter::Chapter() {
	
		setEmpty();
	}

	Chapter::Chapter(const char* chapterName, int pages) {
		
		if (chapterName != nullptr && chapterName[0] != 0 && pages > 0)
		{
			setChapterName(chapterName);
			setPages(pages);
		
		}
		else {
			setEmpty();
		}
	
	}

	void Chapter::setEmpty() {

		m_chapterName[0] = '\0';
		m_chapterPages = 0;

	}

	void Chapter::setChapterName(const char* chptName) {
		
		if (chptName != nullptr) {
			strcpy(m_chapterName, chptName);
		}
		else {
			m_chapterName[0] = '\0';

		}
				
	}

	void Chapter::setPages(int pages) {
	
		if (pages < MAXPAGES) {

			m_chapterPages = pages;
		}
		else {

			//m_chapterPages = 0;
			setEmpty();
		};
		
	}

	void Chapter::addPages(int pages) {

		if (pages < MAXPAGES) {

			m_chapterPages += pages;
		};

		if (m_chapterPages > MAXPAGES) {

			m_chapterPages = MAXPAGES;
		};
	};

	bool Chapter::isEmpty()const {
		return(m_chapterName[0] == 0 || m_chapterPages == 0);
	};



	void Chapter::display()const {

		if (!isEmpty())
		{
			cout.width(50);
			cout.fill('.');
			cout.setf(ios::left);
			cout << m_chapterName;
			cout.unsetf(ios::left);
			cout.width(4);
			cout.fill(' ');
			cout << m_chapterPages;
			cout << endl;

		}
		else
		{
			cout << "invalid Chapter" << endl;
		}
	};

}
