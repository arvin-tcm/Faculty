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
	queue->tail = node;
}
// Dequeue to remove node at head
ValueT deQueue(Queue* queue)
{
	if (isEmpty(queue))
		return -1;
	Node* oldHead = queue->head;
	ValueT output = queue->head->data;
	queue->head = queue->head->nextPtr;
	free(oldHead);
	return output;
}
// Check the queue contains no nodes inside 
int isEmpty(Queue* queue)
{
	if (!queue) return 1;
	if (queue->head || queue->tail) return 1;
	return 0;
}
// Empty all nodes inside the queue
void emptyQueue(Queue* queue)
{

}
// Free all nodes and queue itself
void freeQueue(Queue* queue)
{

}
// Print all elements from head to tail
void printQueue(Queue* queue)
{

}