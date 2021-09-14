#ifndef SDDS_IODRINK_H
#define SDDS_IODRINK_H

namespace sdds {
	
	const int MAXDRINKS = 5;

	struct Drink {
		char name[10];
		int volume;
		double price;
		int quantity;
	};

	


	void loadDrinks();
	void drinkMenu();
	void displayDrink(const Drink* drink);
	int chooseDrink();
	bool updateDrink(int sel);


}

#endif // 

