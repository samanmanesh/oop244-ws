// ===================================================================================
//  Workshop: #1
//  Part: 1 (Lab) 
// ===================================================================================
//  Student Name  : Mohammadhossein Sobhanmanesh
//  Student ID    : 116523200
//  Student Email : msobhanmanesh@myseneca.ca
//  Course Section: OOP244-NAA
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

	void loadDrinksFromFile(const char* filename)



	void drinkMenu();
	void displayDrink(const Drink* drink);
	int chooseDrink();
	bool updateDrink(int sel);


}

#endif // 

