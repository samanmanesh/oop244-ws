#include <iostream>
#include <cstring>
#include "Guests.h"
using namespace sdds;
using namespace std;


namespace sdds {
	
	void read(char* str, int len) {
		if (cin.peek() == '\n') cin.ignore(); // checks the incomming character, if it is newline, it will remove it
		cin.getline(str, len);

		//cout << str << "check " << endl;
	}

	void read(PhoneNumber& thePhoneNumber) {
		cout << "Enter Phone Number [area] [number]: ";
		cin >> thePhoneNumber.m_areacode >> thePhoneNumber.m_number;
	};


	bool read(Guest& theGuest) {
		bool result;
		cout << "Guest name: ";
		read(theGuest.m_name, 20);

		cout << theGuest.m_name << "check 2 " << endl;		
		//bool foo = strcmp(theGuest.m_name, "");

		if (theGuest.m_name[0] != '\0') {
			read(theGuest.m_phno);
			result = true;
		}
		else
		{
			result = false;
		}
		return result;
	}


}