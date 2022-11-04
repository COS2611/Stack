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
