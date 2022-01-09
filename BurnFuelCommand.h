#pragma once
#include "ICommand.h"
#include "CommandException.h"

class BurnFuelCommand : public ICommand
{
public:
	BurnFuelCommand(int* fuel) : _fuel(fuel)
	{

	}
	void Execute()
	{
		if (*_fuel > 0)
			*_fuel = (*_fuel) - 1;
	}
private:
	int *_fuel;
};