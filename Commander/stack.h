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

	//배열 정리 함수
	void Clear()
	{
		//배열을 0으로 전부 초기화
		memset(data, 0, sizeof(T) * maxStack);
		//포인터도 0으로 초기화
		count = 0;
	}

	// 배열 상태 확인 함수
	// 스택이 비었는지 확인.
	bool IsEmpty() const
	{
		return count == 0;
	}

	// 스택이 가득찼는지 확인.
	bool IsFull() const
	{
		return count == maxStack;
	}

	//배열에 명령 입력
	bool push(const T& com)
	{
		//배열 꽉 차있으면 추가 불가
		if (IsFull())
		{
			std::cout << "스택이 가득 찼습니다.\n";
			return false;
		}

		data[count] = com;
		++count;
		return true;
	}

	bool pop(T& value)
	{
		//스택이 비었는지 확인
		if (IsEmpty())
		{
			std::cout << "스택이 비어있습니다.\n";
			return false;
		}
		// 포인터는 현재 실제 데이터가 들어있는 곳보다 하나 높은 곳을 가리키고 있으므로,
		// 한 칸 내리고 pop해야 한다.
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
	
	//현재 스택 포인터가 가리키는 곳
	int count = 0;
};