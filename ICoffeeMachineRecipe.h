#pragma once
#include<cstdint>
#include "Recipe.h"
class ICoffeeMachineRecipe
{
public:
	virtual ~ICoffeeMachineRecipe() {}
	virtual bool SetRecipe(Recipe* recipe) = 0;
};
