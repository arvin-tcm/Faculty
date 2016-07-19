#ifndef STACK_H_
#define STACK_H_
#include<stdlib.h>
#include<stdio.h>
// typedef for the data in node
typedef int ValueT;
// Structure for the node inside stack list
typedef struct nodeT
{
	ValueT data;
	struct nodeT * nextPtr;
}Node;
//Structure for the Stack which hold the head node pointer
typedef struct
{
	Node * head;
}Stack;
// Enumeration for bool data type which C doesn't have(false = 0, true = 1)
typedef enum
{
	false, true
}bool;
// Private function to create a new empty node
static Node* newNode();
// Create a new stack with no node inside
Stack* newStack();
// Push a data to the top of the stack
void push(Stack*, ValueT);
// Remove the top element of the stack and return the data in the head node
ValueT pop(Stack*);
// De-allocate all node in the stack
void emptyStack(Stack*);
// de-allocate all node in the stack and the stack itself
void freeStack(Stack*);
// check the stack has at least one node
bool isEmpty(Stack*);
// pinrt all the elements' data in the stack
void printStack(Stack*);
#endif