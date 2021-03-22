#include "Recipe.h"

 Recipe::Recipe(uint32_t water, uint32_t sugar, uint32_t milk, std::string nameOfDrink) {
	m_ingredientsForRecipe.water = water;
	m_ingredientsForRecipe.sugar = sugar;
	m_ingredientsForRecipe.milk = milk;
	m_nameOfDrink = nameOfDrink;
}

 int Recipe::GetWater() {
	 return m_ingredientsForRecipe.water;
 }

 int Recipe::GetSugar() {
	 return m_ingredientsForRecipe.sugar;
 }

 int Recipe::GetMilk() {
	 return m_ingredientsForRecipe.milk;
 }
