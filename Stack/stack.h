#ifndef STACK
#define STACK

template<typename T, int N>
class Stack
{
public:
	Stack();			/* c-tor */
	~Stack();			/* d-tor */
	void push(T t);		/* push element on stack */
	T& top();			/* return element from the top of stack */
	void pop();			/* delete element from the top of stack */
	size_t size();		/* return how much elements are on stack */
	bool empty();		/* check if stack is empty */
	
private:
	size_t counter = 0;	
	T* root_stack;		

};

template<typename T, int N>
Stack<T, N>::Stack()
{
	root_stack = new T[N];
}

template<typename T, int N>
Stack<T, N>::~Stack()
{
	delete[] root_stack;
}

template<typename T, int N>
void Stack<T, N>::push(T t)
{
	if (counter != N) {
		root_stack[counter] = t;
		counter++;
	}
	else {
		throw std::out_of_range("You want add too much element to stack! ");
	}
}

template<typename T, int N>
T& Stack<T, N>::top()
{
	return root_stack[counter - 1];
}

template<typename T, int N>
void Stack<T, N>::pop()
{
	if (counter > 0) {
		counter--;
	}
	else {
		throw std::out_of_range("Stack is empty! ");
	}
}

template<typename T, int N>
size_t Stack<T, N>::size()
{
	return counter;
}

template<typename T, int N>
bool Stack<T, N>::empty()
{
	return counter <= 0 ? true : false;
}


#endif // !STACK