#include "stdafx.h"

int main()
{
	try {
		Stack<int, 3> stack;
		std::cout << " --- Test Stack ---" << std::endl;
		std::cout << "Add 3 elements to stack" << std::endl;
		stack.push(1);
		stack.push(2);
		stack.push(8);
		//stack.pop();
		std::cout << "Size of stack: " << stack.size() << std::endl;
		std::cout << "Empty stack: " << stack.empty() << std::endl;
		std::cout << "Top of stack: " << stack.top() << std::endl;
		std::cout << " --- End Test ---" << std::endl;
	}
	catch (std::out_of_range& a) {
		std::cout << "Error: " << a.what() << std::endl;
	}
	
	getchar();
    return 0;
}

