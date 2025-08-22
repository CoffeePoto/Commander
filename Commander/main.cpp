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
	//undo ����
	Stack<ICommand*> Undo;
	//Redo ����
	Stack<ICommand*> Redo;
	//Ű���� �Է� ť
	queue<ICommand*> KeyInput;


	//�Է��� command�� a,b,c,d,e�� ���´ٰ� ����
	//q �Է� ������ ����
	while (true)
	{
		char* input = new char[100];
		ICommand* newCommand;
		std::cout << "����� �Է����ּ���(����� q): ";
		std::cin >> input;
		if (strcmp(input, "Q") == 0 || strcmp(input, "q") == 0)
		{
			//std::cin.get()�� �ڲ� ���õǴ� ������ �־�
			//cin ���۸� ����־���.
			std::cin.ignore();
			break;
		}
		if (strcmp(input, "A") == 0 || strcmp(input, "a") == 0)
		{
			//���� ť�� ��� �Է�
			newCommand = new CommandA();
			KeyInput.Enqueue(newCommand);
			//ť���� ��� �����ͼ� �����ϰ�(�ߴ�ġ��) Undo �������� �̻�
			ICommand* commandAction;
			KeyInput.Dequeue(commandAction);
			Undo.push(commandAction);
		}
		else if (strcmp(input, "B") == 0 || strcmp(input, "b") == 0)
		{
			newCommand = new CommandB();
			KeyInput.Enqueue(newCommand);
			//ť���� ��� �����ͼ� �����ϰ�(�ߴ�ġ��) Undo �������� �̻�
			ICommand* commandAction;
			KeyInput.Dequeue(commandAction);
			Undo.push(commandAction);
		}
		else if (strcmp(input, "C") == 0 || strcmp(input, "c") == 0)
		{
			newCommand = new CommandC();
			KeyInput.Enqueue(newCommand);
			//ť���� ��� �����ͼ� �����ϰ�(�ߴ�ġ��) Undo �������� �̻�
			ICommand* commandAction;
			KeyInput.Dequeue(commandAction);
			Undo.push(commandAction);
		}
		else if (strcmp(input, "D") == 0 || strcmp(input, "d") == 0)
		{
			newCommand = new CommandD();
			KeyInput.Enqueue(newCommand);
			//ť���� ��� �����ͼ� �����ϰ�(�ߴ�ġ��) Undo �������� �̻�
			ICommand* commandAction;
			KeyInput.Dequeue(commandAction);
			Undo.push(commandAction);
		}
		else if (strcmp(input, "E") == 0 || strcmp(input, "e") == 0)
		{
			newCommand = new CommandE();
			KeyInput.Enqueue(newCommand);
			//ť���� ��� �����ͼ� �����ϰ�(�ߴ�ġ��) Undo �������� �̻�
			ICommand* commandAction;
			KeyInput.Dequeue(commandAction);
			Undo.push(commandAction);
		}
		else if (!strcmp(input, "undo"))
		{
			//Undo�� ���� ���� ���
			if (Undo.getSize() == 0)
			{
				std::cout << "����� ����� �����ϴ�.\n";
				continue;
			}
			ICommand* restore;
			Undo.pop(restore);
			Redo.push(restore);
		}
		else if (!strcmp(input, "redo"))
		{
			//Redo�� ���� ���� ���
			if (Redo.getSize() == 0)
			{
				std::cout << "������ ����� �����ϴ�.\n";
				continue;
			}
			ICommand* undo;
			Redo.pop(undo);
			Undo.push(undo);
		}
		else
		{
			std::cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���\n";
			continue;
		}

		PrintCommand(Undo);
	}

	//std::cin.get();
	return 0;
}