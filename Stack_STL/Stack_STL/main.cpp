#include <iostream>
#include <stack>

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


//template <class Type>
//void printStack(std::stack<Type> &theStack)
//{
//	if (!theStack.empty())
//	{
//		std::cout << theStack.top() << " ";
//		theStack.pop();
//		return (printStack(&theStack));
//	}
//	else
//	{
//		return;
//	}
//}


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


int main()
{
	std::stack<int> a;
	std::stack<int> b;
	
	
	a.push(1);
	a.push(2);
	a.push(3);
	b = a;
	

	std::cout << "Built-in equality test:\n";
	if (a == b)
	{
		std::cout << "The stacks are identical" << std::endl;
	}
	else
	{
		std::cout << "The stacks are different" << std::endl;
	}
	
	std::cout << "a: ";
	print(a);
	std::cout << "b: ";
	print(b);
	
	std::cout << "User-defined equality test:\n";
	if (identicalStack(a, b))
	{
		std::cout << "The stacks are identical" << std::endl;
	}
	else
	{
		std::cout << "The stacks are different" << std::endl;
	}
	
	std::cout << "a: ";
	print(a);
	std::cout << "b: ";
	print(b);
	

	
	return 0;
}
