#ifndef SDDS_IODRINK_H
#define SDDS_IODRINK_H

namespace sdds {

	struct Drink {
		char name[10];
		int volume;
		double price;
		int quantity;
	};

	Drink machine[MAXDRINKS];


	void loadDrinks();
	void drinkMenu();
	void displayDrink(const Drink* drink);
	int chooseDrink();
	bool updateDrink(int sel);


}

#endif // 

