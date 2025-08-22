#pragma once

#include "ICommand.h"

class CommandB : public ICommand
{
public:
	CommandB()
	{

	}
	~CommandB()
	{
	}
	virtual void Action() override
	{
		std::cout << "This is Command B" << "\n";
	}

	virtual void Undo() override
	{
		std::cout << "Undo Command B" << "\n";
	}

	virtual void Redo() override
	{
		std::cout << "Redo Command B" << "\n";
	}
};