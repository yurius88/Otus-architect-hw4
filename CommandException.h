#pragma once
#include <exception>

class CommandException : public std::exception
{
public:
	CommandException() : std::exception("CommandException")
	{

	}
};