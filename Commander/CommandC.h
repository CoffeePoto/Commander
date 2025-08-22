#pragma once

#include "ICommand.h"

class CommandC : public ICommand
{
public:
	CommandC()
	{

	}
	~CommandC()
	{
	}
	virtual void Action() override
	{
		std::cout << "This is Command C" << "\n";
	}

	virtual void Undo() override
	{
		std::cout << "Undo Command C" << "\n";
	}

	virtual void Redo() override
	{
		std::cout << "Redo Command C" << "\n";
	}
};