#include"Stack.h"
#include<crtdbg.h>
int main()
{
	// Create Stack 
	Stack* myStack = newStack();
	pop(myStack);
	printf("Is empty? %d\n", isEmpty(myStack));
	// Pushing elements into Stack
	for (int i = 0; i < 5; i++)
	{
		push(myStack, i);
	}
	// print all elements in the stack
	printStack(myStack);

	// Remoing all elements from Stack
	printf("Poping all elements from stack:\n");
	while (!isEmpty(myStack))
	{
		printf("value : %d\n", pop(myStack));
	}
	// Memory usage check
	printf("memory leaks before free : %d\n", _CrtDumpMemoryLeaks());
	emptyStack(myStack);
	printf("memory leaks after emptyStack() function : %d\n", _CrtDumpMemoryLeaks());
	freeStack(myStack);
	printf("memory leaks after freeStack() function : %d\n", _CrtDumpMemoryLeaks());
	return 0;
}