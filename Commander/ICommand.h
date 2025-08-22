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
	//Ŀ�ǵ� �� �ٸ� �׼�
	virtual void Action() = 0;
	virtual void Undo() = 0;
	virtual void Redo() = 0;
};
