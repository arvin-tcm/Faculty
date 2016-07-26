#ifndef QUEUE_H_
#define QUEUE_H_
#include<stdio.h>
#include<stdlib.h>
// Typedef for the data type in Queue
typedef int ValueT;
// Structure for the node in Queue
typedef struct node
{
	ValueT data;
	struct ndoe* nextPtr;
}Node;
// Structure for the Queue management
typedef struct queue
{
	Node* head;
	Node* tail;
}Queue;
typedef enum
{
	false, true
}bool;
// Private function to create a new node with initialized data
static Node* newNode();
// Function to create a new Queue with initialization
Queue* newQueue();
// Enqueue to add node at tail
void enQueue(Queue*, ValueT);
// Dequeue to remove node at head
ValueT deQueue(Queue*);
// Check the queue contains no nodes inside 
bool isEmpty(Queue*);
// Empty all nodes inside the queue
void emptyQueue(Queue*);
// Free all nodes and queue itself
void freeQueue(Queue*);
// Print all elements from head to tail
void printQueue(Queue*);
#endif