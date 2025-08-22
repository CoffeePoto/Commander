#pragma once

#include <iostream>

class ICommand
{
public:
	ICommand()
	{

	}
	virtual ~ICommand()
	{
	}
	//커맨드 별 다른 액션
	virtual void Action() = 0;
	virtual void Undo() = 0;
	virtual void Redo() = 0;
};
