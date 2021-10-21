#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Contact.h"
using namespace std;
using namespace sdds;
namespace sdds {

	bool Contact::validPhone(int areaCode, int exchangeCode, int number)const {
		bool result = false;

			if (m_name != nullptr && m_name[0] != 0 && lenght(m_area) == 3 && m_area >= 100 && m_area <= 999 && lenght(m_exchangeCode) == 3 && m_exchangeCode >= 100 && m_exchangeCode <= 999 && m_number >= 0 && m_number <= 9999)
			{
				result = true;
			}
			else
			{
				result = false;
			};

		return result;
	};


	int Contact::lenght(int value) const {
		int valueLength = 0;

		/*if (value == 0) {
			valueLength = 1;
				return valueLength;
		};*/

		do {
			valueLength++;
			value = value / 10;
		} while (value);

		return valueLength;

	}

	void Contact::setEmpty() {
		m_name = nullptr;
	};

	void Contact::allocateAndCopy(const char* name) {
		
		delete[] m_name;
		if (name != nullptr && name[0] != 0)
		{
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
	};

	void Contact:: extractChar(std::istream& istr, char ch)const {
		
		if (istr.peek() == ch) {
			istr.get();
		}
		else
		{
			istr.setstate(ios::failbit);
		}
	
	};

	ostream& Contact::printPhoneNumber(ostream& istr)const {
		
		istr << "(" << m_area << ") " << m_exchangeCode << "-";
		istr.setf(ios::right);
		istr.fill('0');
		istr.width(4);
		istr << m_number;
		istr.fill(' ');
	};

	void Contact::set(const char* name, int areaCode, int exchangeCode, int number) {
	
		if (validPhone) {
			allocateAndCopy(name);
			m_area = areaCode;
			m_exchangeCode = exchangeCode;
			m_number = number;
		}
		else
		{
			delete[] m_name;
			setEmpty();
		}
	
	};


	Contact::Contact() {
			
		setEmpty();
		m_area = 0;
		m_exchangeCode = 0;
		m_name = 0;
	};
	Contact::Contact(char* name, int areaCode, int exchangeCode, int number) {
	
		set(name, areaCode, exchangeCode, number);
	};


	Contact::Contact(const Contact& cnt){
		if (cnt.m_name)
		{
			set(cnt.m_name, cnt.m_area, cnt.m_exchangeCode, cnt.m_number);
		}
		else {

			setEmpty();
		}

	};


	Contact& Contact::operator=(const Contact& cnt) {
		
		if (this != &cnt)
		{
			//delete[] m_name;
			set(cnt.m_name, cnt.m_area, cnt.m_exchangeCode, cnt.m_number);
		}
		return *this;
	};


	Contact::~Contact() {
		delete[] m_name;
	};


	Contact::operator bool() const {
		return  m_name != nullptr;
	}



}	




