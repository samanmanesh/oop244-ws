// ===================================================================================
//  Workshop: #2
//  Part: 1 (Lab) 
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Date          : 2020-09-21
//  Course Section: OOP244-NAA
// ===================================================================================
// I have done all the coding by myself and only copied the code that my professor 
// provided to complete my workshops and assignments.
// ===================================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Fighter.h" 
using namespace std;
using namespace sdds;

namespace sdds {

	void fighter(char* name) {

		cout << "Enter Fighter Name: ";
		cin >> *name;
	}
	
	void fighter(int& power) {
		cout << "Enter Fighter Power: ";
		cin >> power;
	}

	void display(const Fighter& myFighter) {

		cout << "Name: " << myFighter.name <<", Power: " << myFighter.power << endl;

	}

	void display(const Competition& mycompetition) {	
		int i;

		for ( i = 0; i < mycompetition.numfighters; i++)
		{
			display(mycompetition.fighters[i]);
		}

	}

	void addFighter(Competition& myCompetition) {
		int prevSize = myCompetition.numfighters;
		int newSize = prevSize + 1;
		
		Fighter* newFighter = nullptr;
		newFighter = new Fighter[newSize];

		
			for (int i = 0; i < newSize; i++)
			{
				//newFighter[i].name = myCompetition.fighters[i].name;
				/*for (int j = 0; j < MAX_NAME+1; j++)
				{
					newFighter[i].name[j] = myCompetition.fighters[i].name[j];
				}*/

				strcpy(newFighter[i].name, myCompetition.fighters[i].name);
				newFighter[i].power = myCompetition.fighters[i].power;
			};
				
			cout << "Enter the information of the new fighter:" << endl;
			fighter(newFighter[newSize].name);
			fighter(newFighter[newSize].power);

			delete[] myCompetition.fighters;
			myCompetition.fighters = nullptr;

			myCompetition.fighters = newFighter;
			myCompetition.numfighters++;
	}


	int findFighter(const Competition& mycompetition, const Fighter& theFighter) {
		int foundIndex = -1;

		for (int i = 0; i < mycompetition.numfighters; i++)
		{
			if (mycompetition.fighters[i].name == theFighter.name)  foundIndex = i;
		}

		return foundIndex;
	}

	void removeFighter(Competition& mycompetition, const Fighter& loserFighter) {
		int prevSize = mycompetition.numfighters;
		int newSize = prevSize - 1;

		Fighter* newFighter = nullptr;
		newFighter = new Fighter[newSize];
		int loserFighterIndex = findFighter(mycompetition, loserFighter);

		if (loserFighterIndex != -1) {

			for (int i = 0; i < newSize; i++)
			{
				if (i != loserFighterIndex) {
					//if (mycompetition.fighters[loserFighterIndex].name != mycompetition.fighters[i].name){
					strcpy(newFighter[i].name, mycompetition.fighters[i].name);
					newFighter[i].power = mycompetition.fighters[i].power;
				}
			}

			mycompetition.numfighters--;
		}

		delete[] mycompetition.fighters;
		mycompetition.fighters = nullptr;

		mycompetition.fighters = newFighter;


	}

	bool fight(const Fighter& f1, const Fighter& f2) {
		bool result = false;
		
		if (f1.power > f2.power) result = true;
		return result;
	}

	void fight(Competition& mycompetition, Fighter& f1, Fighter& f2) {

		cout << "    " << f1.name << " will fight " << f2.name << "..." << endl;

		if (fight(f1, f2)) {
			
			removeFighter(mycompetition, f2);
			cout << "    The winner => " << f1.name << endl;
		}
		else
		{
			removeFighter(mycompetition, f1);
			cout << "    The winner => " << f2.name << endl;
		}


	}

}