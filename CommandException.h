#pragma once
#include <exception>

class CommandException : public std::exception
{
public:	
	char const* what() const override
	{
		return "CommandException";
	}
};
