#include <iostream>
#include <cstring>
#include "Guests.h"
using namespace sdds;
using namespace std;


namespace sdds {

	void read(char* str, int len) {
		if (cin.peek() == '\n') cin.ignore(); // checks the incomming character, if it is newline, it will remove it
		cin.getline(str, len);
	}

	void read(PhoneNumber& thePhoneNumber) {
		cout << "Enter Phone Number [area] [number]: ";
		cin >> thePhoneNumber.m_areacode >> thePhoneNumber.m_number;
	};


	bool read(Guest& theGuest) {
		bool result;
		cout << "Guest name: ";
		read(theGuest.m_name, 20);
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

	void print(const PhoneNumber& thePhoneNumber) {
		cout << "(" << thePhoneNumber.m_areacode << ") " << thePhoneNumber.m_number << endl;
	}

	void print(const Guest& theGuest) {

		cout << theGuest.m_name << ", ";
		print(theGuest.m_phno);

	}

	void print(const GuestList& theGuestList) {
		int len = theGuestList.m_noOfGuests;
			for (int i = 0; i < len; i++)
			{
				cout << i + 1 << "- ";
				print(theGuestList.m_gst[i]);
			}
	}





}