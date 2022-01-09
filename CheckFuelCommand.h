#pragma once
#include "ICommand.h"
#include "CommandException.h"

class CheckFuelCommand : public ICommand
{
public:
	CheckFuelCommand(int* fuel) : _fuel(fuel)
	{

	}
	void Execute()
	{
		if (*_fuel < 1)
			throw CommandException();
	}
private:
	int *_fuel;
};