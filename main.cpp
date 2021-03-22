#include <iostream>
#include <cstdint>
#include "CoffeeMachine.h"

ICoffeeMachine& CreateCoffeeMachine() {
	Recipe* americano;
	americano = new Recipe(20, 1, 0, "americano");

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

	try
	{
	machine.MakeLatte();
	machine.MakeAmericano();
	}
	catch (const std::exception& error)
	{
		std::cout << error.what() << std::endl;
	}

	CoffeeMachine saeco(1000, 1000, 1000);
	Recipe* americano;
	americano = new Recipe(5520, 1, 0, "americano");

	Recipe* latte;
	latte = new Recipe(180, 6, 80, "latte");

	try
	{
		saeco.SetRecipe(americano);		
		saeco.MakeAmericano();
		
	}
	catch (const std::exception& error)
	{
		std::cout << error.what()<<std::endl;
	}

	try
	{
		saeco.SetRecipe(latte);
		saeco.MakeLatte();
	}
	catch (const std::exception& error)
	{
		std::cout << error.what() << std::endl;
	}

	std::cout << "GetWater - " << saeco.GetWater() << std::endl;
	std::cout << "GetMilk - " << saeco.GetMilk() << std::endl;
	std::cout << "GetSugar - " << saeco.GetSugar() << std::endl;
}