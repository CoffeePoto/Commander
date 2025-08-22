#pragma once
#include <iostream>

const int maxStack = 100;
template<typename T>
class Stack
{
public:
	Stack() = default;
	~Stack()
	{
	}

	T& operator[](int index)
	{
		if (index < 0 || index >= count)
		{
			__debugbreak();
		}
		return data[index];
	}

	//�迭 ���� �Լ�
	void Clear()
	{
		//�迭�� 0���� ���� �ʱ�ȭ
		memset(data, 0, sizeof(T) * maxStack);
		//�����͵� 0���� �ʱ�ȭ
		count = 0;
	}

	// �迭 ���� Ȯ�� �Լ�
	// ������ ������� Ȯ��.
	bool IsEmpty() const
	{
		return count == 0;
	}

	// ������ ����á���� Ȯ��.
	bool IsFull() const
	{
		return count == maxStack;
	}

	//�迭�� ��� �Է�
	bool push(const T& com)
	{
		//�迭 �� �������� �߰� �Ұ�
		if (IsFull())
		{
			std::cout << "������ ���� á���ϴ�.\n";
			return false;
		}

		data[count] = com;
		++count;
		return true;
	}

	bool pop(T& value)
	{
		//������ ������� Ȯ��
		if (IsEmpty())
		{
			std::cout << "������ ����ֽ��ϴ�.\n";
			return false;
		}
		// �����ʹ� ���� ���� �����Ͱ� ����ִ� ������ �ϳ� ���� ���� ����Ű�� �����Ƿ�,
		// �� ĭ ������ pop�ؾ� �Ѵ�.
		--count;
		value = data[count];
		return true;
	}

	int getSize() const
	{
		return count;
	}

private:
	T data[maxStack] = { };
	
	//���� ���� �����Ͱ� ����Ű�� ��
	int count = 0;
};