#pragma once
class ICoffeeMachine
{
public:
	virtual ~ICoffeeMachine() {}
	virtual bool MakeAmericano() = 0;
	virtual bool MakeLatte() = 0;
};
