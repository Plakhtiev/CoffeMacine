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
	Recipe(uint32_t water, uint32_t sugar, uint32_t milk, std::string nameOfDrink) {
		m_ingredientsForRecipe.water = water;
		m_ingredientsForRecipe.sugar = sugar;
		m_ingredientsForRecipe.milk = milk;
		m_nameOfDrink = nameOfDrink;
	};

	std::string GetNameOfDrink() {
		return m_nameOfDrink;
	}

	int GetWater() {
		return m_ingredientsForRecipe.water;
	}
	int GetSugar() {
		return m_ingredientsForRecipe.sugar;
	}
	int GetMilk() {
		return m_ingredientsForRecipe.milk;
	}

private:
	IngredientsForRecipe  m_ingredientsForRecipe = {};
	std::string m_nameOfDrink;
};