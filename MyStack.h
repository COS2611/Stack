#ifndef H_StackType
#define H_StackType
 
#include <iostream>
#include <cassert>
#include "StackADT.h"


template <class Type>
class StackType: public StackADT<Type>
{
public:
    const StackType<Type>& operator=(const StackType<Type>&); 
      //Overload the assignment operator.

    void initializeStack();
      //Function to initialize the stack to an empty state.
      //Postcondition: stackTop = 0;

    bool isEmptyStack() const;
      //Function to determine whether the stack is empty.
      //Postcondition: Returns true if the stack is empty,
      //    otherwise returns false.

    bool isFullStack() const;
      //Function to determine whether the stack is full.
      //Postcondition: Returns true if the stack is full,
      //    otherwise returns false.

    void push(const Type& newItem);
      //Function to add newItem to the stack.
      //Precondition: The stack exists and is not full.
      //Postcondition: The stack is changed and newItem is
      //    added to the top of the stack.

    Type top() const;
      //Function to return the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: If the stack is empty, the program 
      //    terminates; otherwise, the top element of the stack
      //    is returned.

    void pop();
      //Function to remove the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: The stack is changed and the top element is
      //    removed from the stack.

    StackType(int stackSize = 100); 
      //Constructor
      //Create an array of the size stackSize to hold 
      //the stack elements. The default stack size is 100.
      //Postcondition: The variable list contains the base address 
      //   of the array, stackTop = 0, and maxStackSize = stackSize

    StackType(const StackType<Type>& otherStack); 
      //Copy constructor

    ~StackType(); 
      //Destructor
      //Remove all the elements from the stack.
      //Postcondition: The array (list) holding the stack 
      //    elements is deleted.

private:
    int maxStackSize; 	//variable to store the maximum stack size
    int stackTop;     	//variable to point to the top of the stack
    Type *list; 		//pointer to the array that holds the stack elements

    void copyStack(const StackType<Type>& otherStack); 
      //Function to make a copy of otherStack.
      //Postcondition: A copy of otherStack is created and assigned
      //    to this stack.
};



template <class Type>
bool sameStack (StackType<Type> s, StackType<Type> w)
// Tests whether two stacks contain the same elements
// Returns true if the stacks contain the same elements.
// Returns false otheriwse.
// (Exam question uses pass by value)
{
	if (s.isEmptyStack() && w.isEmptyStack())	// both stacks are empty
	{
		return true;
	}

	else if (s.isEmptyStack() || w.isEmptyStack())	// one of the stacks, but not both is empty
	{
		return false;
	}

	else if (s.top() != w.top())	// the first elements differ
	{
		return false;
	}

	else // both stacks are not empty
	{
		s.pop();
		w.pop();
		return sameStack(s, w);	// recursive function call
	}
}


template <class Type>
const StackType<Type>& StackType<Type>::operator=(const StackType<Type>& otherStack)
{
	if (this != &otherStack)	// avoid self-copy
	{
		copyStack(otherStack);
	}
	return *this;
}


template <class Type>
void StackType<Type>::initializeStack()
{
	stackTop = 0;
}

template <class Type>
bool StackType<Type>::isEmptyStack() const
{
	return (stackTop == 0);
}

template <class Type>
bool StackType<Type>::isFullStack() const
{
	return (stackTop == maxStackSize);
}

template <class Type>
void StackType<Type>::push(const Type& newItem)
{
	if (!isFullStack())	// make sure that the stack is not full (avoid overflow)
	{
		list[stackTop] = newItem;	// store newItem at the top of the stack
		stackTop++;					// increment stackTop
	}
	
	else
	{
		std::cout << "Cannot add to a full stack." << std::endl;
	}
}

template <class Type>
Type StackType<Type>::top() const
{
	assert (stackTop != 0);
	return (list[stackTop - 1]);
}

template <class Type>
void StackType<Type>::pop()
{
	if (!isEmptyStack())	// avoid underflow
	{
		stackTop--;
	}
	
	else
	{
		std::cout << "Cannot remove from an empty stack." << std::endl;
	}
}

template <class Type>
StackType<Type>::StackType(int stackSize)
{
	if (stackSize <= 0)
	{
		std::cout << "Size of the array to hold the stack must be positive." << std::endl;
		std::cout << "Creating array of size 100." << std::endl;
		maxStackSize = 100;
	}
	
	else
	{
		maxStackSize = stackSize;
	}
	stackTop = 0;
	list = new Type[maxStackSize];
}

template <class Type>
StackType<Type>::StackType(const StackType<Type>& otherStack)
{
	list = NULL;
	copyStack(otherStack);
}

template <class Type>
void StackType<Type>::copyStack(const StackType<Type>& otherStack)
{
	delete[] list;
	maxStackSize = otherStack.maxStackSize;
	stackTop = otherStack.stackTop;
	list = new Type[maxStackSize];
	
	for (int j = 0; j < stackTop; j++)
	{
		list[j] = otherStack.list[j];
	}
}


template <class Type>
StackType<Type>::~StackType<Type>()
{
	delete[] list;
}

#endif
