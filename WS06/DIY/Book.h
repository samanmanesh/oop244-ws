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

    const int MaxBookTitileLength = 40;
    const int MaxAuthorNameLength = 25;
    const int MaxBookCaseNum = 132;
    const int MaxShelfNum = 7;

    class Book {
        char* m_bookTitle{}; // sets m_name to nullptr before any constructor invocation 
        char* m_authorName{};
        int m_bookCaseNum;
        int m_shelfNum;
        
        bool validBook(char* bookTitle, char* authorName, int bookCaseNum, int shelfNum)const;
       
    public:

       
    };

    
}
#endif // !SDDS_BOOK_H
