#include"Stack.h"
static Node* newNode()
{
	// Allocate new Node memory space
	Node* newNode = (Node*)malloc(sizeof(Node));
	// Initialize the data in this new node
	newNode->data = 0;
	newNode->nextPtr = NULL;
	return newNode;
}
Stack* newStack()
{
	// Allocate new Stack memory space
	Stack* newStack = (Stack*)malloc(sizeof(Stack));
	// Initialize the head pointer in this new stack
	newStack->head = NULL;
	return newStack;
}
void push(Stack* stack, ValueT input)
{
	// Create new node
	Node* newHead = newNode();
	// Insert the data
	newHead->data = input;
	// update the new head memory location
	newHead->nextPtr = stack->head;
	stack->head = newHead;
}
ValueT pop(Stack* stack)
{
	// Get the data from the head node
	ValueT output = stack->head->data;
	// Get the memory location form the head pointer
	Node* oldHead = stack->head;
	// Update the new head memory location
	stack->head = stack->head->nextPtr;
	// Remove the old head node
	free(oldHead);
	// Return the data
	return output;
}
void emptyStack(Stack* stack)
{
	// Keep poping elements unitl the stack has no node
	while (!isEmpty(stack))
		pop(stack);
}
void freeStack(Stack* stack)
{
	// Remove all nodes
	emptyStack(stack);
	// Remove the stack
	free(stack);
}
bool isEmpty(Stack* stack)
{
	// stack is empty when Stack pointer is not NULL and the head pointer is NULL
	if (stack != NULL && stack->head == NULL)
		return true; // 1
	else
		return false; // 0
}
void printStack(Stack* stack)
{
	// Start the print from the head of the stack
	Node* iterator = stack->head;
	while (iterator != NULL)
	{
		printf("data: %d\t\tmemory loaction: %d\n", iterator->data, &(iterator->data));
		// iteration
		iterator = iterator->nextPtr;
	}
}