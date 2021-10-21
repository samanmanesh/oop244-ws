#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include <iostream>
namespace sdds {
    
    const int MaxNameLength = 55;

    class Contact {
        char* m_name{}; // sets m_name to nullptr before any constructor invocation 
        int m_area;
        int m_exchangeCode;
        int m_number;

        bool validPhone(int areaCode, int exchangeCode, int number)const;
        int lenght(int value) const;

        void setEmpty();

        void allocateAndCopy(const char* name);

        void extractChar(std::istream& istr, char ch)const;

       std::ostream& printPhoneNumber(std::ostream& istr)const;

        void set(const char* name, int areaCode, int exchangeCode, int number);
    public:
        
        Contact();
        Contact(char* name, int areaCode, int exchangeCode, int number);

        Contact(const Contact& cnt);
        Contact& operator=(const Contact& cnt);

        ~Contact();

        operator bool() const;

       std::ostream& print(std::ostream& ostr, bool toFile = true) const;
       std::istream& read(std::istream& istr);
    };

    std::ostream& operator<<(std::ostream& ostr, const Contact& cnt);
    std::istream& operator>>(std::istream& istr, Contact& cnt);
}
#endif // !SDDS_CONTACT_H


