//Program to test the various operations of a stack
 
#include <iostream>
#include "tests.h"


int main()
{
	test_transferStack();
	
	std::cout << "\nTesting isInLanguageL:\n";
	testIsInLanguageL();
	
	std::cout << "\nTesting isInLanguageL2:\n";
	testIsInLanguageL2();
	
	std::cout << "\nTesting isInLanguageL3:\n";
	testIsInLanguageL3();
	
	return 0;
}
