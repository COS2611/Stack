//Program to test the various operations of a stack
 
#include <iostream>
#include <string>
#include "MyStack.h"

void testCopyConstructor(StackType<int> otherStack);
static void printStack(StackType<int> &theStack);


int main()
{
	std::string w = "abb";
	if (isInLanguageL(w))
	{
		std::cout << w << " is in the language L" << std::endl;
	}
	
	else
	{
		std::cout << w << " is not in the language L" << std::endl;
	}
	
	return 0;
}


void testCopyConstructor(StackType<int> otherStack)
{
	if (!otherStack.isEmptyStack())
	{
		std::cout 	<< "otherStack is not empty." << std::endl
					<< "The top element of otherStack: "
					<< otherStack.top() << std::endl;
	}
}

static void printStack(StackType<int> &theStack)
{
	while (!theStack.isEmptyStack())
	{
		std::cout << theStack.top() << " ";
		theStack.pop();
	}
	std::cout << std::endl;
}


