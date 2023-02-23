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
	std::string empty = "";
	std::string a = "a";
	std::string b = "b";
	std::string ab = "ab";
	std::string aab = "aab";
	std::string abb = "abb";
	std::string aabb = "aabb";
	std::string aaaba = "aaaba";
	std::string aaabb = "aaabb";
	std::string aabbb = "aabbb";
	std::string aaabbbb = "aaabbbb";
	std::string aaaabbbbb = "aaaabbbbb";
	std::string aaaabbbbba = "aaaabbbbba";
	std::string aaababbbbb = "aaababbbbb";
	assert(isInLanguageL(empty) == false);
	assert(isInLanguageL(a) == false);
	assert(isInLanguageL(b) == false);
	assert(isInLanguageL(ab) == true);
	assert(isInLanguageL(aab) == false);
	assert(isInLanguageL(abb) == false);
	assert(isInLanguageL(aabb) == true);
	assert(isInLanguageL(aaaba) == false);
	assert(isInLanguageL(aaabb) == false);
	assert(isInLanguageL(aabbb) == false);
	assert(isInLanguageL(aaabbbb) == false);
	assert(isInLanguageL(aaaabbbbb) == false);
	assert(isInLanguageL(aaaabbbbba) == false);
	assert(isInLanguageL(aaababbbbb) == false);
	
}

// test case: COS2611-06-2020: Q4.1
// L2 = {a^n b^n+1}
static void testIsInLanguageL2()
{
	std::string empty = "";
	std::string a = "a";
	std::string b = "b";
	std::string ab = "ab";
	std::string aab = "aab";
	std::string abb = "abb";
	std::string aabb = "aabb";
	std::string aaaba = "aaaba";
	std::string aaabb = "aaabb";
	std::string aabbb = "aabbb";
	std::string aaabbbb = "aaabbbb";
	std::string aaaabbbbb = "aaaabbbbb";
	std::string aaaabbbbba = "aaaabbbbba";
	std::string aaababbbbb = "aaababbbbb";
	assert(isInLanguageL2(empty) == false);
	assert(isInLanguageL2(a) == false);
	assert(isInLanguageL2(b) == false);
	assert(isInLanguageL2(ab) == false);
	assert(isInLanguageL2(aab) == false);
	assert(isInLanguageL2(abb) == true);
	assert(isInLanguageL2(aabb) == false);
	assert(isInLanguageL2(aaaba) == false);
	assert(isInLanguageL2(aaabb) == false);
	assert(isInLanguageL2(aabbb) == true);
	assert(isInLanguageL2(aaabbbb) == true);
	assert(isInLanguageL2(aaaabbbbb) == true);
	assert(isInLanguageL2(aaaabbbbba) == false);
	assert(isInLanguageL2(aaababbbbb) == false);
	
}

// L = {a^n b^n-1}
static void testIsInLanguageL3()
{
	std::string empty = "";
	std::string a = "a";
	std::string b = "b";
	std::string ab = "ab";
	std::string aab = "aab";
	std::string abb = "abb";
	std::string aabb = "aabb";
	std::string aaaba = "aaaba";
	std::string aaabb = "aaabb";
	std::string aabbb = "aabbb";
	std::string aaabbbb = "aaabbbb";
	std::string aaaabbbbb = "aaaabbbbb";
	std::string aaaabbbbba = "aaaabbbbba";
	std::string aaababbbbb = "aaababbbbb";
	assert(isInLanguageL3(empty) == false);
	assert(isInLanguageL3(a) == true);
	assert(isInLanguageL3(b) == false);
	assert(isInLanguageL3(ab) == false);
	assert(isInLanguageL3(aab) == true);
	assert(isInLanguageL3(abb) == false);
	assert(isInLanguageL3(aabb) == false);
	assert(isInLanguageL3(aaaba) == false);
	assert(isInLanguageL3(aaabb) == true);
	assert(isInLanguageL3(aabbb) == false);
	assert(isInLanguageL3(aaabbbb) == false);
	assert(isInLanguageL3(aaaabbbbb) == false);
	assert(isInLanguageL3(aaaabbbbba) == false);
	assert(isInLanguageL3(aaababbbbb) == false);
	
	
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

static void test_reverseS()
{
	stackType<int> myStack;
	myStack.push(5);
	myStack.push(4);
	myStack.push(3);
	myStack.push(2);
	myStack.push(1);
	
	std::cout << "My stack before reverse: ";
	printStack(myStack);
	
	reverseS(myStack);
	std::cout << "My stack after reverse: ";
	printStack(myStack);
}

#endif /* tests_h */
