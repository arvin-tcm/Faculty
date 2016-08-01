#include"Queue.h"
int main()
{
	Queue* myQueue = newQueue();
	for (int i = 0; i < 5; i++)
	{
		enQueue(myQueue, i);
	}
	printQueue(myQueue);
	emptyQueue(myQueue);
	freeQueue(myQueue);
	return 0;
}