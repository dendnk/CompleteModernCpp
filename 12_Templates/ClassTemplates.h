#pragma once

template<typename T, int size>
class Stack
{
	T Buffer[size];
	int Top{ -1 };

public:
	Stack() = default;
	Stack(const Stack<T, size>& Other)
	{
		Top = Other.Top;
		for (int i(0); i <= Top; ++i)
		{
			Buffer[i] = Other.Buffer[i];
		}
	}

	void Push(const T& Elem)
	{
		Buffer[++Top] = Elem;
	}

	void Pop();

	const T& GetTop() const
	{
		return Buffer[Top];
	}

	bool IsEmpty()
	{
		return Top == -1;
	}

	static Stack Create();
};

template<typename T, int size>
void Stack<T, size>::Pop()
{
	--Top;
}

template<typename T, int size>
Stack<T, size> Stack<T, size>::Create()
{
	return Stack<T, size>();
}

void ClassTemplatesMain();
