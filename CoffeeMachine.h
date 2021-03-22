#pragma once
#include "ICoffeeMachine.h"
#include "ICoffeeMachineRecipe.h"
#include "Recipe.h"
#include "ErrorCoffeeMachine.h"

struct IngredientsInMachine
{
	uint32_t water;
	uint32_t sugar;
	uint32_t milk;
};

class CoffeeMachine :
	public ICoffeeMachine,
	public ICoffeeMachineRecipe
{
public:
	CoffeeMachine(uint32_t water, uint32_t sugar, uint32_t milk);
	~CoffeeMachine();

	// Inherited via ICoffeeMachine
	bool SetRecipe(Recipe* recipe) override;

	void SetWater(uint32_t water);

	void SetSugar(uint32_t sugar);

	void SetMilk(uint32_t milk);

	uint32_t GetWater();

	uint32_t GetSugar();

	uint32_t GetMilk();

	uint32_t GetRecipesAmount();

	bool MakeAmericano();
	bool MakeLatte();
private:
	bool DecreaseIngredients(const std::string& nametRecipes);

private:
	static const uint32_t m_recipesAmount = 10;
	IngredientsInMachine m_currContainMachine = {};
	Recipe* m_recipes[m_recipesAmount] = {};
};
