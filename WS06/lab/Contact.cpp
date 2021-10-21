#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Contact.h"
using namespace std;
using namespace sdds;
namespace sdds {

	bool Contact::validPhone(int areaCode, int exchangeCode, int number)const {
		bool result = false;
		
		/*if (m_name != nullptr && m_name[0] != 0
			&& lenght(m_area) == 3 && m_area >= 100
			&& m_area <= 999 && lenght(m_exchangeCode) == 3
			&& m_exchangeCode >= 100 && m_exchangeCode <= 999
			&& m_number >= 0 && m_number <= 9999)
		{*/

		if ( lenght(areaCode) == 3 && areaCode >= 100 
			&& areaCode <= 999 && lenght(exchangeCode) == 3 
			&& exchangeCode >= 100 && exchangeCode <= 999 
			&& number >= 0 && number <= 9999)
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
		//m_name = nullptr;
		if (name != nullptr && name[0] != 0)
		{
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
	};

	void Contact::extractChar(std::istream& istr, char ch)const {

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
		istr.unsetf(ios::right);
		return istr;
	};

	void Contact::set(const char* name, int areaCode, int exchangeCode, int number) {

		if ( name != nullptr && name[0] != 0 && validPhone( areaCode, exchangeCode, number)) {
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

	Contact::Contact(const char* name, int areaCode, int exchangeCode, int number) {
		
		//setEmpty();
		set(name, areaCode, exchangeCode, number);
	};


	Contact::Contact(const Contact& cnt) {
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

	ostream& Contact::print(ostream& ostr, bool toFile ) const {
		
		if (*this){

			if (toFile)
			{
				ostr << m_name;
				ostr << ",";
			}
			else if(toFile == false)
			{
				ostr.width(50);
				ostr.setf(ios::left);
				ostr.fill('.');
				ostr << m_name;
				ostr.setf(ios::right);
				ostr.fill(' ');
			}
			printPhoneNumber(ostr);
		}
		return ostr;
	};

	istream& Contact::read(istream& istr) {
		
		char name[128];
		int areaCode;
		int exchangeCode;
		int number;
		istr.get(name, MaxNameLength, ',');
		extractChar(istr, ',');
		extractChar(istr, '(');
		istr >> areaCode;
		extractChar(istr, ')');
		extractChar(istr, ' ');
		istr >> exchangeCode;
		extractChar(istr, '-');
		istr >> number;
		extractChar(istr, '\n');

		if (!istr.fail())
		{
			set(name, areaCode, exchangeCode, number);
		}
		//else {
		//	// Its maybe an obtional thing I put here
		//	istr.clear();
		//}
		return istr;
	};


	ostream& operator<<(ostream& ostr, const Contact& cnt) {
		
		if (cnt) {
			cnt.print(ostr, false);
		}
		else
		{
			ostr << "Invalid Phone Record" << endl;
		}
		return ostr;
	
	};

	istream& operator>>(istream& istr, Contact& cnt) {
		return (cnt.read(istr));
	}
}




