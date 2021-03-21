#pragma once
#include <iostream>
#include"CoffeeMachine.h"
#include "Recipe.h"

class ErrorCoffeeMachine : public std::runtime_error
{
public: ErrorCoffeeMachine(const char* msg, int errorCode);
	  int GetErrorCode();
private:
	int m_errorCode = 0;
};