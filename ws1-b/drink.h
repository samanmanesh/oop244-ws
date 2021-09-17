// ===================================================================================
//  Workshop: #1
//  Part: 2 (DIY) 
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Date          : 
//  Course Section: OOP244-NAA
// ===================================================================================
// I have done all the coding by myself and only copied the code that my professor 
// provided to complete my workshops and assignments.
// ===================================================================================

#ifndef SDDS_IODRINK_H
#define SDDS_IODRINK_H

namespace sdds {

	struct Drink {
		char name[10];
		int volume;
		double price;
		int quantity;
	};

	
	//void loadDrinks();

	void loadDrinksFromFile(const char* filename);



	void drinkMenu();
	void displayDrink(const Drink* drink);
	int chooseDrink();
	bool updateDrink(int sel);


}

#endif // 

