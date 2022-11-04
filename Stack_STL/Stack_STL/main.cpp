#include <iostream>
#include <stack>
#include <string>

template <class Type>
static void print(std::stack<Type> &theStack)
{
	while (!theStack.isEmptyStack())
	{
		std::cout << theStack.top() << " ";
		theStack.pop();
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


bool isInLanguageL(std::string w)
{
	std::stack<char> s;
	unsigned int index = 0;
	
	while (w[index] == 'a')	// add '-' to the stack for every occurrence of 'a'
	{
		s.push('-');
		index++;
	}
	
	while (w[index] == 'b')	// pop the top element of the stack for every occurrence of 'b'
	{
		s.pop();
		index++;
	}
	
	if (s.empty())	// if the stack is empty and index == wordlength: return true
	{
		return index == w.length();
	}
	
	// else return false
	else
	{
		return false;
	}
}


int main()
{
	std::string w = "ab";
	
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
