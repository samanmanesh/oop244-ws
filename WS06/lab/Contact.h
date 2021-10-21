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

    public:
        
    };
}
#endif // !SDDS_CONTACT_H


