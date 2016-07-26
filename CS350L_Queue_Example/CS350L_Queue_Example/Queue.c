#include"Queue.h"
// Private function to create a new node with initialized data
static Node* newNode()
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = 0;
	node->nextPtr = NULL;
	return node;
}
// Function to create a new Queue with initialization
Queue* newQueue()
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->head = NULL;
	queue->tail = NULL;
	return queue;
}
// Enqueue to add node at tail
void enQueue(Queue* queue, ValueT input)
{
	Node* node = newNode();
	node->data = input;
	node->nextPtr = NULL;
	if (isEmpty(queue))
	{
		queue->head = node;
		queue->tail = node;
	}
	else
	{
		queue->tail->nextPtr = node;
		queue->tail = node;
	}
}
// Dequeue to remove node at head
ValueT deQueue(Queue* queue)
{
	if (isEmpty(queue))
	{
		return -1;
	}
	Node* oldHead = queue->head;
	ValueT output = queue->head->data;
	queue->head = queue->head->nextPtr;
	// additional memory address handling required
	if (!queue->head)
	{
		queue->tail = NULL;
	}
	free(oldHead);
	return output;
}
// Check the queue contains no nodes inside 
bool isEmpty(Queue* queue)
{
	if (!queue) return false;
	if (!queue->head && !queue->tail) return true;
	return false;
}
// Empty all nodes inside the queue
void emptyQueue(Queue* queue)
{
	while (queue->head != NULL)
	{
		deQueue(queue);
	}
}
// Free all nodes and queue itself
void freeQueue(Queue* queue)
{
	emptyQueue(queue);
	free(queue);
}
// Print all elements from head to tail
void printQueue(Queue* queue)
{
	Node* iterator = queue->head;
	while (iterator != NULL)
	{
		printf("Data: %d\tAddress: %d\tNext Address: %d\n", iterator->data, iterator, iterator->nextPtr);
		iterator = iterator->nextPtr;
	}
}