#pragma once

#include "ICommand.h"

class CommandE : public ICommand
{
public:
	CommandE()
	{

	}
	~CommandE()
	{
	}
	virtual void Action() override
	{
		std::cout << "This is Command E" << "\n";
	}

	virtual void Undo() override
	{
		std::cout << "Undo Command E" << "\n";
	}

	virtual void Redo() override
	{
		std::cout << "Redo Command E" << "\n";
	}
};