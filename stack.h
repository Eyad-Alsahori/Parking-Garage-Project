#pragma once
#ifndef Stackh
#define Stackh

#include<cstdlib>
#include<iostream>
using namespace std;

template<class StackType>
class Stack
{
public:
	Stack(); // DEFAULT  CONSTRUCTOR
	Stack(int MaxStackSize); // CONSTRUCTOR
	~Stack();
	bool IsEmpty() const;
	bool IsFull() const;
	StackType Top() const;
	void push(const StackType& x);
	void pop();
private:
	int top; //  CURRENT  TOP OF STACK
	int MaxTop;
	StackType* stack; // ELEMENT
};

template<class StackType>
Stack<StackType>::Stack()
{
	MaxTop = 10;
	stack = new StackType[MaxTop];
	top = -1;
}

template<class StackType>
Stack<StackType>::Stack(int MaxStackSize)
{
	MaxTop = MaxStackSize - 1;
	stack = new StackType[MaxStackSize];
	top = -1;
}

template<class StackType>
Stack<StackType>::~Stack()
{
	delete[] stack;
}

template<class StackType>
bool Stack<StackType>::IsEmpty() const
{
	if (top == -1)
		return true;
	else
		return false;
}

template<class StackType>
bool Stack<StackType>::IsFull() const
{
	if (top == MaxTop - 1)
		return true;
	else
		return false;
}

template<class StackType>
StackType Stack<StackType>::Top() const
{
	if (IsEmpty())
	{
		cout << "The stack is empty" << endl;
	}
	else
	{
		return stack[top];
	}
}

template<class StackType>
void Stack<StackType>::push(const StackType& x)
{
	if (IsFull())
	{
		cout << "The stack is full" << endl;
	}
	else
	{
		top++;
		stack[top] = x;
	}
}

template<class StackType>
void Stack<StackType>::pop()
{
	if (IsEmpty())
	{
		cout << "The stack is empty" << endl;
	}
	else
	{
		top--;
	}
}
#endif


