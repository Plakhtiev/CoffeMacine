#include <iostream>
#include <cstdint>
#include "CoffeeMachine.h"

ICoffeeMachine& CreateCoffeeMachine() {
	Recipe* americano;
	americano = new Recipe(50, 1, 0, "americano");

	Recipe* latte;
	latte = new Recipe(80, 3, 30, "latte");

	static CoffeeMachine rowenta(1800, 1000, 1000);
	rowenta.SetRecipe(americano);
	rowenta.SetRecipe(latte);
	return rowenta;
}

int main()
{

	ICoffeeMachine& machine = CreateCoffeeMachine();

	machine.MakeAmericano();

	CoffeeMachine mach(1000, 1000, 1000);

	Recipe* americano;
	americano = new Recipe(20, 1, 0, "americano");

	Recipe* latte;
	latte = new Recipe(180, 6, 80, "latte");

	mach.SetRecipe(americano);
	mach.SetRecipe(latte);
	mach.MakeAmericano();
	mach.MakeLatte();

	std::cout << "GetWater - " << mach.GetWater() << std::endl;
	std::cout << "GetMilk - " << mach.GetMilk() << std::endl;
	std::cout << "GetSugar - " << mach.GetSugar() << std::endl;
}