#pragma once

#include "ICommand.h"

class CommandD : public ICommand
{
public:
	CommandD()
	{

	}
	~CommandD()
	{
	}
	virtual void Action() override
	{
		std::cout << "This is Command D" << "\n";
	}

	virtual void Undo() override
	{
		std::cout << "Undo Command D" << "\n";
	}

	virtual void Redo() override
	{
		std::cout << "Redo Command D" << "\n";
	}
};