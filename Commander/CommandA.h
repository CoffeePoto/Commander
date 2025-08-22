#pragma once

#include "ICommand.h"

class CommandA : public ICommand
{
public:
	CommandA()
	{

	}
	~CommandA()
	{
	}
	virtual void Action() override
	{
		std::cout << "This is Command A" << "\n";
	}

	virtual void Undo() override
	{
		std::cout << "Undo Command A" << "\n";
	}

	virtual void Redo() override
	{
		std::cout << "Redo Command A" << "\n";
	}
};