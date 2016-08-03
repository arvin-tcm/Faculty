#include"Stack.h"
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
	emptyStack(myStack);
	freeStack(myStack);
	return 0;
}