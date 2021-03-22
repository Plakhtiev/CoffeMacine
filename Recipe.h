#pragma once
#include <iostream>
#include <cstdint>

struct IngredientsForRecipe
{
	uint32_t water;
	uint32_t sugar;
	uint32_t milk;
};

class Recipe
{
public:
	Recipe(uint32_t water, uint32_t sugar, uint32_t milk, std::string nameOfDrink);

	std::string GetNameOfDrink() {
		return m_nameOfDrink;
	}

	int GetWater();
	int GetSugar();
	int GetMilk();

private:
	IngredientsForRecipe  m_ingredientsForRecipe = {};
	std::string m_nameOfDrink;
};