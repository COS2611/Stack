#include <iostream>
#include <stack>
#include <string>
#include <cassert>

template <class Type>
static void printStack(const std::stack<Type> &theStack)
{
	// create a copy of the stack to maintain its data
	std::stack<Type> tempStack = theStack;
	
	while (!tempStack.empty())
	{
		std::cout << tempStack.top() << " ";
		tempStack.pop();
	}
	std::cout << std::endl;
}



template <class Type>
bool identicalStack(std::stack<Type> &s1, std::stack<Type> &s2)
{
	if (s1.empty() && s2.empty())	// both stacks are empty
	{
		return true;
	}
	
	else if (s1.empty() || s2.empty())	// only one stack is empty
	{
		return false;
	}
	
	else 	// both stacks are not empty
	{
		if (s1.top() != s2.top())	// first elements differ
		{
			return false;
		}
		s1.pop();
		s2.pop();
		return identicalStack(s1, s2);
	}
}


template <class Type>
void transferStack(std::stack<Type>& s1, std::stack<Type>& s2)
{
	// Transfers elements from s1 to s2.
	// The order of the elements is maintained.
	
	// Create a temp stack to store the elements from s1
	std::stack<Type> tempStack;
	
	// Move elements from s1 to temp stack
	while (!s1.empty())
	{
		tempStack.push(s1.top());
		s1.pop();
	}
	
	// Move elements from temp stack to s2
	while (!tempStack.empty())
	{
		s2.push(tempStack.top());
		tempStack.pop();
	}
}


bool isInLanguageL(std::string w)
{
	std::stack<char> s;
	unsigned int index = 0;
	
	// add '-' to the stack for every occurrence of 'a'
	while (w[index] == 'a')
	{
		s.push('-');
		index++;
	}
	
	// remove '-' from the stack for every occurrence of 'b'
	while (w[index] == 'b' && !s.empty())
	{
		s.pop();
		index++;
	}
	
	// if the stack is empty: the word is in L
	if (s.empty())
	{
		return index == w.size();
	}
	
	else // else the word is not in L
	{
		return false;
	}
}


static void wordIsInLanguage()
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
}


static void test_transferStack()
{
	std::stack<int> myStack;
	std::stack<int> yourStack;
	
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
	assert(myStack.empty());
}

int main()
{
	test_transferStack();
		
	return 0;
}
