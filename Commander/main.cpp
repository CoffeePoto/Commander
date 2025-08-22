#include "stack.h"
#include "queue.h"
#include "CommandA.h"
#include "CommandB.h"
#include "CommandC.h"
#include "CommandD.h"
#include "CommandE.h"

void PrintCommand(Stack<ICommand*> stack)
{
	for (int i = 0; i < stack.getSize(); ++i)
	{
		ICommand* command = stack[i];
		command->Action();
	}
}

int main()
{
	//undo 스택
	Stack<ICommand*> Undo;
	//Redo 스택
	Stack<ICommand*> Redo;
	//키보드 입력 큐
	queue<ICommand*> KeyInput;


	//입력은 command인 a,b,c,d,e가 들어온다고 가정
	//q 입력 받으면 종료
	while (true)
	{
		char* input = new char[100];
		ICommand* newCommand;
		std::cout << "명령을 입력해주세요(종료는 q): ";
		std::cin >> input;
		if (strcmp(input, "Q") == 0 || strcmp(input, "q") == 0)
		{
			//std::cin.get()이 자꾸 무시되는 경향이 있어
			//cin 버퍼를 비워주었다.
			std::cin.ignore();
			break;
		}
		if (strcmp(input, "A") == 0 || strcmp(input, "a") == 0)
		{
			//먼저 큐에 명령 입력
			newCommand = new CommandA();
			KeyInput.Enqueue(newCommand);
			//큐에서 명령 가져와서 실행하고(했다치고) Undo 스택으로 이사
			ICommand* commandAction;
			KeyInput.Dequeue(commandAction);
			Undo.push(commandAction);
		}
		else if (strcmp(input, "B") == 0 || strcmp(input, "b") == 0)
		{
			newCommand = new CommandB();
			KeyInput.Enqueue(newCommand);
			//큐에서 명령 가져와서 실행하고(했다치고) Undo 스택으로 이사
			ICommand* commandAction;
			KeyInput.Dequeue(commandAction);
			Undo.push(commandAction);
		}
		else if (strcmp(input, "C") == 0 || strcmp(input, "c") == 0)
		{
			newCommand = new CommandC();
			KeyInput.Enqueue(newCommand);
			//큐에서 명령 가져와서 실행하고(했다치고) Undo 스택으로 이사
			ICommand* commandAction;
			KeyInput.Dequeue(commandAction);
			Undo.push(commandAction);
		}
		else if (strcmp(input, "D") == 0 || strcmp(input, "d") == 0)
		{
			newCommand = new CommandD();
			KeyInput.Enqueue(newCommand);
			//큐에서 명령 가져와서 실행하고(했다치고) Undo 스택으로 이사
			ICommand* commandAction;
			KeyInput.Dequeue(commandAction);
			Undo.push(commandAction);
		}
		else if (strcmp(input, "E") == 0 || strcmp(input, "e") == 0)
		{
			newCommand = new CommandE();
			KeyInput.Enqueue(newCommand);
			//큐에서 명령 가져와서 실행하고(했다치고) Undo 스택으로 이사
			ICommand* commandAction;
			KeyInput.Dequeue(commandAction);
			Undo.push(commandAction);
		}
		else if (!strcmp(input, "undo"))
		{
			//Undo할 것이 없는 경우
			if (Undo.getSize() == 0)
			{
				std::cout << "취소할 명령이 없습니다.\n";
				continue;
			}
			ICommand* restore;
			Undo.pop(restore);
			Redo.push(restore);
		}
		else if (!strcmp(input, "redo"))
		{
			//Redo할 것이 없는 경우
			if (Redo.getSize() == 0)
			{
				std::cout << "복구할 명령이 없습니다.\n";
				continue;
			}
			ICommand* undo;
			Redo.pop(undo);
			Undo.push(undo);
		}
		else
		{
			std::cout << "잘못된 입력입니다. 다시 입력하세요\n";
			continue;
		}

		PrintCommand(Undo);
	}

	//std::cin.get();
	return 0;
}