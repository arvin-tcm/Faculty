#include"Queue.h"
#include<crtdbg.h>
int main()
{
	Queue* myQueue = newQueue();
	printQueue(myQueue);
	deQueue(myQueue);
	for (int i = 0; i < 5; i++)
	{
		enQueue(myQueue, i);
	}
	printQueue(myQueue);
	printf("Is empty?: %d\n", isEmpty(myQueue));
	emptyQueue(myQueue);
	printf("Is empty?: %d\n", isEmpty(myQueue));
	freeQueue(myQueue);
	printf("Memory Leaks?: %d\n", _CrtDumpMemoryLeaks());
	return 0;
}