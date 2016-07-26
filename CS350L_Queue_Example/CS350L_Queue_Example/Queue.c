#include"Queue.h"
// Private function to create a new node with initialized data
static Node* newNode()
{

}
// Function to create a new Queue with initialization
Queue* newQueue()
{
	
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
		return false;
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

}
// Free all nodes and queue itself
void freeQueue(Queue* queue)
{
	emptyQueue(queue);
	free(queue);
}