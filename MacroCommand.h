#pragma once
#include "ICommand.h"
#include <vector>

class MacroCommand : public ICommand
{
public:
	MacroCommand(std::vector<ICommand*> cmds) : _cmds(cmds)
	{

	}
	void Execute()
	{		
		for (ICommand* cmd : _cmds)
		{
			cmd->Execute();
		}
	}
private:
	std::vector<ICommand*> _cmds;
};