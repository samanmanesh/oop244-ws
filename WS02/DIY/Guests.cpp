// ===================================================================================
//  Workshop: #2
//  Part: 2 (DIY)
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Date          : 2020-09-25
//  Course Section: OOP244-NAA
// ===================================================================================
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
// ===================================================================================

#define _CRT_SECURE_NO_WARNINGS
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


	void addGuest(GuestList& theGuestList, const Guest& aGuest) {
		int prevSize = theGuestList.m_noOfGuests;
		int newSize = theGuestList.m_noOfGuests + 1;
		Guest* newGuestPtr = nullptr;
		newGuestPtr = new Guest[newSize];

		for (int i = 0; i < prevSize; i++)
		{
			strcpy(newGuestPtr[i].m_name, theGuestList.m_gst[i].m_name);
			newGuestPtr[i].m_phno = theGuestList.m_gst[i].m_phno;
		}

		strcpy(newGuestPtr[prevSize].m_name, aGuest.m_name);
		newGuestPtr[prevSize].m_phno = aGuest.m_phno;
		delete[] theGuestList.m_gst;
		theGuestList.m_gst = newGuestPtr;
		newGuestPtr = nullptr;
		theGuestList.m_noOfGuests++;
	}



}