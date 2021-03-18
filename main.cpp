#include <iostream>
#include <cstdint>
#include "ICoffeeMachineRecipe.h"
#include "ICoffeeMachineRecipe.h"
#include "CoffeeMachine.h"
#include "Recipe.h"

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
	
}