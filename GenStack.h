#include <iostream>
#include <fstream>
#ifndef GENSTACK_H
#define GENSTACK_H
//the stack
template <class T>
class GenStack
{
private:
	int size;
	int top;
	T *myArray;
public:
	GenStack();
	GenStack(int maxSize);
	~GenStack();

	void push(T d);
	T pop();
	T peek();
	bool isFull();
	bool isEmpty();
};
template <class T>
GenStack<T>::GenStack()
{
	myArray = new T[128];
	size = 128;
	top = -1;
}
template <class T>
GenStack<T>::GenStack(int maxSize)
{
	myArray = new char[maxSize];
	size = maxSize;
	top = -1;
}
template <class T>
GenStack<T>::~GenStack()
{
	delete [] myArray;
}
//stack push
template <class T>
void GenStack<T>::push(T d)
{
	if(isFull())
	{
		cout << "Stack is full" << endl;
	}
	else
	{
		myArray[++top] = d;
	}
}
//stack pop
template <class T>
T GenStack<T>::pop()
{
	if(isEmpty())
	{
		cout << "Stack is empty" << endl;
	}
	else
	{
		return myArray[top--];
	}
}
//stack peek
template <class T>
T GenStack<T>::peek()
{
	if(isEmpty())
	{
		cout << "Stack is empty" << endl;
	}
	else
	{
		return myArray[top];
	}
}
//stack is full
template <class T>
bool GenStack<T>::isFull()
{
	return (top == size - 1);
}
//stack is empty
template <class T>
bool GenStack<T>::isEmpty()
{
	return (top == -1);
};
#endif
