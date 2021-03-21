#include "ErrorCoffeeMachine.h"

struct ErrorMsg
{
	std::string errorRecipeAdd = "No recipe has been added";
	std::string errorIngredients = "Not enough ingredients for ";
};

ErrorCoffeeMachine::ErrorCoffeeMachine(const char* msg, int errorCode) :
	std::runtime_error(msg)
{
	m_errorCode = errorCode;
}

int ErrorCoffeeMachine::GetErrorCode()
{
	return m_errorCode;
}