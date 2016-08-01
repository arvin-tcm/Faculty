#include"Queue.h"
// Private function to create a new node with initialized data
static Node* newNode()
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data;
	node->nextPtr = NULL;
	return node;
}
// Function to create a new Queue with initialization
Queue* newQueue()
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->front = NULL;
	queue->rear = NULL;
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
	if (!queue) return true;
	if (!queue->front && !queue->rear) return true;
	return false;
}
// Empty all nodes inside the queue
void emptyQueue(Queue* queue)
{
	while (queue->front != NULL)
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
void printQueue(Queue* queue)
{
	Node* iterator = queue->front;
	while (iterator != NULL)
	{
		printf("%d\t%d\n", iterator->data, iterator);
		iterator = iterator->nextPtr;
	}
}
