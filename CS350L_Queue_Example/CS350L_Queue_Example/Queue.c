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
		queue->front = node;
		queue->rear = node;
	}
	else
	{
		queue->rear->nextPtr = node;
		queue->rear = node;
	}
}
// Dequeue to remove node at head
ValueT deQueue(Queue* queue)
{
	if (isEmpty(queue))
	{
		return false;
	}
	Node* oldHead = queue->front;
	ValueT output = queue->front->data;
	queue->front = queue->front->nextPtr;
	// additional memory address handling required
	if (!queue->front)
	{
		queue->rear = NULL;
	}
	free(oldHead);
	return output;
}
// Check the queue contains no nodes inside 
bool isEmpty(Queue* queue)
{
	if (!queue) return false;
	if (!queue->front && !queue->rear) return true;
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