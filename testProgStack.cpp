//Program to test the various operations of a stack
 
#include <iostream>
#include <string>
#include "MyStack.h"

void testCopyConstructor(StackType<int> otherStack);
static void printStack(StackType<int> &theStack);

// test case: COS2611-06-2020: Q4.1
static void testIsInLanguageL2() {
	std::string a = "aaaabbbbb";
	std::string b = "aaababbbbb";
	std::string c = "aaaabbbbba";
	std::string s1 = isInLanguageL2(a) ? " is ACCEPTED" : " is REJECTED";
	std::string s2 = isInLanguageL2(b) ? " is ACCEPTED" : " is REJECTED";
	std::string s3 = isInLanguageL2(c) ? " is ACCEPTED" : " is REJECTED";
	std::cout << a + s1 << std::endl;
	std::cout << b + s2 << std::endl;
	std::cout << c + s3 << std::endl;
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


static void testSameStack() {
	
	// test case 1: both stacks are empty
	{
		StackType<char> s1;
		StackType<char> s2;
		
		if (sameStack(s1, s2))
		{
			std::cout << "The stacks are identical" << std::endl;
		}
		else
		{
			std::cout << "The stacks are different" << std::endl;
		}
	}
	
	// test case 2: only one stack is empty
	{
		StackType<char> s1;
		StackType<char> s2;
		
		s1.push('a');
		s1.push('e');
		s1.push('i');
		s1.push('o');
		s1.push('u');
		
		if (sameStack(s1, s2))
		{
			std::cout << "The stacks are identical" << std::endl;
		}
		else
		{
			std::cout << "The stacks are different" << std::endl;
		}
	}
	
	// Test case 3: Both stacks are non-empty, but top elements differ
	// at some point
	{
		StackType<char> s1;
		StackType<char> s2;
		
		s1.push('a');
		s1.push('e');
		s1.push('i');
		s1.push('o');
		s1.push('u');
		
		s2.push('a');
		s2.push('e');
		s2.push('i');
		s2.push('z');
		s2.push('u');
		
		if (sameStack(s1, s2))
		{
			std::cout << "The stacks are identical" << std::endl;
		}
		else
		{
			std::cout << "The stacks are different" << std::endl;
		}
	}
	
	// Test case 4: Both stacks are non-empty and the same
	{
		StackType<char> s1;
		StackType<char> s2;
		
		s1.push('a');
		s1.push('e');
		s1.push('i');
		s1.push('o');
		s1.push('u');
		
		s2.push('a');
		s2.push('e');
		s2.push('i');
		s2.push('o');
		s2.push('u');
		
		if (sameStack(s1, s2))
		{
			std::cout << "The stacks are identical" << std::endl;
		}
		else
		{
			std::cout << "The stacks are different" << std::endl;
		}
	}
}

static void testSameStack_case() {
	StackType<char> s1;
	StackType<char> s2;
	
	s1.push('a');
	s1.push('e');
	s1.push('i');
	s1.push('o');
	s1.push('u');
	
	s2.push('a');
	s2.push('e');
	s2.push('i');
	s2.push('o');
	s2.push('u');
	
	if (sameStack(s1, s2))
	{
		std::cout << "The stacks are identical" << std::endl;
	}
	else
	{
		std::cout << "The stacks are different" << std::endl;
	}
}

int main()
{
	// test sameStack
	testSameStack();
	
	
	return 0;
}
