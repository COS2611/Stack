//Program to test the various operations of a stack
 
#include <iostream>
#include "MyStack.h"

void testCopyConstructor(StackType<int> otherStack);
static void printStack(StackType<int> &theStack);


int main()
{
//	StackType<int> stack(50);
//	StackType<int> copyStack(50);
//	StackType<int> dummyStack(100);
//
//	stack.initializeStack();
//	stack.push(23);
//	stack.push(45);
//	stack.push(38);
//	copyStack = stack;	// copy stack into copyStack
//
//	std::cout << "The elements of stack: ";
//	printStack(stack);
//
//	std::cout << "The elements of copyStack: ";
//	printStack(copyStack);
//
//	copyStack = stack;
//	testCopyConstructor(stack);	// test the copy constructor
//
//	if (!stack.isEmptyStack())
//	{
//		std::cout 	<< "The original stack is not empty." << std::endl
//					<< "The top element of the original stack: "
//					<< copyStack.top() << std::endl;
//	}
//
//	dummyStack = stack;	// copy stack into dummyStack
//	std::cout << "The elements of dummyStack: ";
//	printStack(dummyStack);
//
//
//	/// test sameStack
//	stack.push(100);
//	stack.push(200);
//	copyStack.push(100);
//	copyStack.push(200);
//
//	if (sameStack(stack, copyStack))
//	{
//		std::cout << "The stacks are identical" << std::endl;
//	}
//
//	else
//	{
//		std::cout << "The stacks are different" << std::endl;
//	}
//
//	std::cout << "The elements of stack: ";
//	printStack(stack);
//
//	std::cout << "The elements of copyStack: ";
//	printStack(copyStack);
	
	StackType<int> s1;
	StackType<int> s2;
	
	s1.push(1);
	s1.push(2);
	s1.push(3);
	
	s1.reverseStack(s2);
	printStack(s2);
	printStack(s1);
	
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


