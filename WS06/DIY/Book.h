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

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
namespace sdds {

    const int MaxTitleLen = 40;
    const int MaxAuthorLen = 25;
    const int NoOfBookCases = 132;
    const int NoOfShelves = 7;

    class Book {
        char* m_bookTitle{}; // sets m_name to nullptr before any constructor invocation 
        char* m_authorName{};
        int m_bookCaseNum;
        int m_shelfNum;
        
        bool validBook(const char* bookTitle,const char* authorName, int bookCaseNum, int shelfNum)const;
       
        void setEmpty();

        void allocateAndCopy(const char* bookTitle, const char* authorName);

        void set(const char* bookTitle, const char* authorName, int bookCaseNum, int shelfNum);

    public:

        Book();
        Book(const char* bookTitle, const char* authorName, int bookCaseNum, int shelfNum);
        
        Book(const Book& bookToBeCopied);
        Book& operator=(const Book& bookToBeCopied);

        operator bool() const;

        std::ostream& write(std::ostream& ostr, bool onScreen = true)const;
       
    };

    
}
#endif // !SDDS_BOOK_H
