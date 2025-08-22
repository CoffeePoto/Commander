#pragma once

const int maxQueue = 100;
template<typename T>
class queue
{
public:
	queue()
	{
		memset(Tarray, 0, sizeof(T) * maxQueue);
	}

	bool isEmpty() const
	{
		return front == rear;
	}

	bool isFull() const
	{
		return (rear + 1) % maxQueue == front;
	}

	bool Enqueue(T newData)
	{
		if (isFull())
		{
			std::cout << "Error: queue is full.\n";
			return false;
		}

		rear = (rear + 1) % maxQueue;
		Tarray[rear] = newData;
		return true;
	}

	bool Dequeue(T& value)
	{
		if (isEmpty())
		{
			std::cout << "Error: queue is empty\n";
			return false;
		}
		front = (front + 1) % maxQueue;
		value = Tarray[front];
		return true;
	}

	//for 
private:
	T Tarray[maxQueue + 1] = { };
	int front = 0;
	int rear = 0;
};
