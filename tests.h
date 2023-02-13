//
//  tests.h
//  Stack
//
//  Created by Mitch Campbell on 2023/02/13.
//

#ifndef tests_h
#define tests_h

#include <string>
#include "MyStack.h"

// L = {a^n b^n}
static void testIsInLanguageL()
{
	std::string a = "ab";
	std::string b = "aabb";
	std::string c = "aaaabbbbba";
	std::string s1 = isInLanguageL(a) ? " is ACCEPTED" : " is REJECTED";
	std::string s2 = isInLanguageL(b) ? " is ACCEPTED" : " is REJECTED";
	std::string s3 = isInLanguageL(c) ? " is ACCEPTED" : " is REJECTED";
	std::cout << a + s1 << std::endl;
	std::cout << b + s2 << std::endl;
	std::cout << c + s3 << std::endl;
}

// test case: COS2611-06-2020: Q4.1
// L2 = {a^n b^n+1}
static void testIsInLanguageL2()
{
	std::string a = "abb";
	std::string b = "aabbb";
	std::string c = "aaaabbbbb";
	std::string d = "aaaabbbbba";
	std::string s1 = isInLanguageL2(a) ? " is ACCEPTED" : " is REJECTED";
	std::string s2 = isInLanguageL2(b) ? " is ACCEPTED" : " is REJECTED";
	std::string s3 = isInLanguageL2(c) ? " is ACCEPTED" : " is REJECTED";
	std::string s4 = isInLanguageL2(d) ? " is ACCEPTED" : " is REJECTED";
	std::cout << a + s1 << std::endl;
	std::cout << b + s2 << std::endl;
	std::cout << c + s3 << std::endl;
	std::cout << d + s4 << std::endl;
}

// L = {a^n b^n-1}
static void testIsInLanguageL3()
{
	std::string a = "a";
	std::string b = "aab";
	std::string c = "aaabb";
	std::string d = "aaaba";
	std::string s1 = isInLanguageL3(a) ? " is ACCEPTED" : " is REJECTED";
	std::string s2 = isInLanguageL3(b) ? " is ACCEPTED" : " is REJECTED";
	std::string s3 = isInLanguageL3(c) ? " is ACCEPTED" : " is REJECTED";
	std::string s4 = isInLanguageL3(d) ? " is ACCEPTED" : " is REJECTED";
	std::cout << a + s1 << std::endl;
	std::cout << b + s2 << std::endl;
	std::cout << c + s3 << std::endl;
	std::cout << d + s4 << std::endl;
	
	assert(isInLanguageL3("aab") == true);
	assert(isInLanguageL3("aaabb") == true);
	assert(isInLanguageL3("ab") == false);
	assert(isInLanguageL3("a") == true);

}

template <class Type>
static void printStack(stackType<Type> theStack)
{
	while (!theStack.isEmptyStack())
	{
		std::cout << theStack.top() << " ";
		theStack.pop();
	}
	std::cout << std::endl;
}

void testCopyConstructor(stackType<int> otherStack)
{
	if (!otherStack.isEmptyStack())
	{
		std::cout 	<< "otherStack is not empty." << std::endl
					<< "The top element of otherStack: "
					<< otherStack.top() << std::endl;
	}
}

static void testSameStack() {
	
	// test case 1: both stacks are empty
	{
		stackType<char> s1;
		stackType<char> s2;
		
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
		stackType<char> s1;
		stackType<char> s2;
		
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
		stackType<char> s1;
		stackType<char> s2;
		
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
		stackType<char> s1;
		stackType<char> s2;
		
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
	stackType<char> s1;
	stackType<char> s2;
	
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

static void test_transferStack()
{
	stackType<int> myStack;
	stackType<int> yourStack;
	
	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	myStack.push(4);
	myStack.push(5);
	
	std::cout << "Before transfer:\n";
	std::cout << "My stack: ";
	printStack(myStack);
	std::cout << "Your stack: ";
	printStack(yourStack);
	
	transferStack(myStack, yourStack);
	std::cout << "\nAfter transfer:\n";
	std::cout << "My stack: ";
	printStack(myStack);
	std::cout << "Your stack: ";
	printStack(yourStack);
	std::cout << std::endl;
	
	// my stack must be empty after transfer
	assert(myStack.isEmptyStack());
}

#endif /* tests_h */
