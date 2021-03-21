#include "CoffeeMachine.h"
#include<iostream>

CoffeeMachine::CoffeeMachine(uint32_t water, uint32_t sugar, uint32_t milk)
{
	m_currContainMachine.sugar = sugar;
	m_currContainMachine.water = water;
	m_currContainMachine.milk = milk;
}

CoffeeMachine::~CoffeeMachine()
{
	for (int i = 0; i < 10; ++i) {
		if (!m_recipes[i]) {
			delete m_recipes[i];
		}
	}
}

// Inherited via ICoffeeMachine

bool CoffeeMachine::SetRecipe(Recipe* recipe)
{
	for (int i = 0; i < 10; ++i) {
		if (!m_recipes[i]) {
			m_recipes[i] = recipe;
			return true;
		}
	}
	throw ErrorCoffeeMachine("Recipe list is full", 23);
}

void CoffeeMachine::SetWater(uint32_t water) {
	m_currContainMachine.water = water;
}

void CoffeeMachine::SetSugar(uint32_t sugar) {
	m_currContainMachine.sugar = sugar;
}

void CoffeeMachine::SetMilk(uint32_t milk) {
	m_currContainMachine.milk = milk;
}

uint32_t CoffeeMachine::GetWater() {
	return m_currContainMachine.water;
}

uint32_t CoffeeMachine::GetSugar() {
	return m_currContainMachine.sugar;
}

uint32_t CoffeeMachine::GetMilk() {
	return m_currContainMachine.milk;
}

uint32_t CoffeeMachine::GetRecipesAmount()
{
	return m_recipesAmount;
}

bool CoffeeMachine::MakeAmericano() {
	static const char* nameDrink = "americano";
	return DecreaseIngredients(nameDrink);
}

bool CoffeeMachine::MakeLatte() {
	static const char* nameDrink = "latte";
	return DecreaseIngredients(nameDrink);
}

bool CoffeeMachine::DecreaseIngredients(const std::string& nameOfRecipes) {
	if (!m_recipes[0]) {
		throw ErrorCoffeeMachine("No recipe has been added", 21);
	}
	for (int i = 0; m_recipes[i]; ++i) {
		if (nameOfRecipes == m_recipes[i]->GetNameOfDrink()) {
			if (m_recipes[i]->GetMilk() <= m_currContainMachine.milk &&
				m_recipes[i]->GetSugar() <= m_currContainMachine.sugar &&
				m_recipes[i]->GetWater() <= m_currContainMachine.water) {
				m_currContainMachine.milk -= m_recipes[i]->GetMilk();
				m_currContainMachine.sugar -= m_recipes[i]->GetSugar();
				m_currContainMachine.water -= m_recipes[i]->GetWater();
				return true;
			}
			else {
				throw ErrorCoffeeMachine("Not enough ingredients", 11);
			}
		}
	}
	throw ErrorCoffeeMachine("No recipe for such a drink", 22);
}