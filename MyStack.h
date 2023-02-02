#ifndef H_stackType
#define H_stackType
 
#include <iostream>
#include <cassert>
#include "StackADT.h"


bool isInLanguageL(std::string w);
// tests whether a word, w is in L, where w = a^nb^n

bool isInLanguageL2(std::string w);
// tests whether a word, w is in L, where w = a^nb^n+1

bool isInLanguageL3(std::string w);
// tests whether a word, w is in L, where w = a^nb^n-1


template <class Type>
class stackType: public StackADT<Type>
{
public:
    const stackType<Type>& operator=(const stackType<Type>&);
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
	
	void reverseStack(stackType<Type> &otherStack);
	// copies the elements of a stack into another stack in reverse order
	// postcondition: the contents of the destination stack are destroyed
	// and the original stack remains unchanged
	
    stackType(int stackSize = 100);
      //Constructor
      //Create an array of the size stackSize to hold 
      //the stack elements. The default stack size is 100.
      //Postcondition: The variable list contains the base address 
      //   of the array, stackTop = 0, and maxStackSize = stackSize

    stackType(const stackType<Type>& otherStack);
      //Copy constructor

    ~stackType();
      //Destructor
      //Remove all the elements from the stack.
      //Postcondition: The array (list) holding the stack 
      //    elements is deleted.

private:
    int maxStackSize; 	//variable to store the maximum stack size
    int stackTop;     	//variable to point to the top of the stack
    Type *list; 		//pointer to the array that holds the stack elements

    void copyStack(const stackType<Type>& otherStack);
      //Function to make a copy of otherStack.
      //Postcondition: A copy of otherStack is created and assigned
      //    to this stack.
};



template <class Type>
bool sameStack (stackType<Type> s, stackType<Type> w) // synonym: identicalStack
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
void stackType<Type>::reverseStack(stackType<Type> &theStack)
{
	theStack.initializeStack();
	
	while (!this->isEmptyStack())
	{
		theStack.push(this->top());
		this->pop();
	}
}


template <class Type>
const stackType<Type>& stackType<Type>::operator=(const stackType<Type>& otherStack)
{
	if (this != &otherStack)	// avoid self-copy
	{
		copyStack(otherStack);
	}
	return *this;
}


template <class Type>
void stackType<Type>::initializeStack()
{
	stackTop = 0;
}

template <class Type>
bool stackType<Type>::isEmptyStack() const
{
	return (stackTop == 0);
}

template <class Type>
bool stackType<Type>::isFullStack() const
{
	return (stackTop == maxStackSize);
}

template <class Type>
void stackType<Type>::push(const Type& newItem)
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
Type stackType<Type>::top() const
{
	assert (stackTop != 0);
	return (list[stackTop - 1]);
}

template <class Type>
void stackType<Type>::pop()
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
stackType<Type>::stackType(int stackSize)
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
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
	list = NULL;
	copyStack(otherStack);
}

template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
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
stackType<Type>::~stackType<Type>()
{
	delete[] list;
}



// L = {a^n b^n}
bool isInLanguageL(std::string w)
{
	stackType<char> s;
	int index = 0;
	while (w[index] == 'a')
	{
		s.push('x');
		index++;
	}
		
	while (w[index] == 'b')
	{
		if (!s.isEmptyStack() && s.top() == 'x')
		{
			s.pop();
		}
		else
		{
			return false;
		}
		index++;
	}
	return (index == w.length() && s.isEmptyStack());
}


// L = {a^n, b^n+1}
bool isInLanguageL2(std::string w)
{
	stackType<char> s;
	int index = 0;
	while (w[index] == 'a')
	{
		s.push('x');
		index++;
	}
	
	// Special case: add an extra 'b', since L = {a^n, b^n+1}
	if (w[index] == 'b')
	{
		s.push('x');
	}
	
	while (w[index] == 'b')
	{
		if (!s.isEmptyStack() && s.top() == 'x')
		{
			s.pop();
		}
		else
		{
			return false;
		}
		index++;
	}
	return (index == w.length() && s.isEmptyStack());
}

// L = {a^n b ^n-1}
bool isInLanguageL3(std::string w)
{
	// Special case: The word is "a" (no b's present)
	if (w == "a") { return true; }
	
	stackType<char> s;
	int index = 0;
	while (w[index] == 'a')
	{
		s.push('x');
		index++;
	}
	
	// Special case: remove an extra 'b', since L = {a^n, b^n-1}
	if (w[index] == 'b')
	{
		s.pop();
	}

	while (w[index] == 'b')
	{
		if (!s.isEmptyStack() && s.top() == 'x')
		{
			s.pop();
		}
		else
		{
			return false;
		}
		index++;
	}
	return (index == w.length() && s.isEmptyStack());
}



//Write a function transferStack that transfers  elements from stack S1 to stack S2. The order of the elements must remain as they were on the original stack S1. You may use one additional stack.
template <class Type>
void transferStack (stackType <Type> &S1, stackType<Type> &S2)
{
	stackType<Type> tempStack;
	
	if (S1.isEmptyStack())
	{
		std::cout << "The original stack is empty\n";
		return;
	}
	
	// transfer elements to temp stack
	while (!S1.isEmptyStack() && !tempStack.isFullStack())
	{
		tempStack.push(S1.top());
		S1.pop();
	}
	
	// transer from temp stack to S2
	while (!tempStack.isEmptyStack() && !S2.isFullStack())
	{
		S2.push(tempStack.top());
		tempStack.pop();
	}
}

#endif

