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

#ifndef SDDS_CHAPTER_H
#define SDDS_CHAPTER_H

namespace sdds {
	
	const int MAXPAGES = 200; //max pages of a book
	const int MAXCHAPTERNAMESIZE = 51;
	class Chapter
	{
		char m_chapterName[51];		// holds the chapter name up to 50 chars
		int m_chapterPages;			   //number of pages of chapter. 

	public:

		Chapter();

		Chapter(const char* chapterName, int pages);


		void setEmpty();
		
		void setChapterName(const char* chptName);

		void setPages(int pages);

		void addPages(int pages);

		bool isEmpty()const;

		int getPages()const;
			
		void display()const;
	};

}

#endif