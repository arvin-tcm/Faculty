#include"Queue.h"
#include<crtdbg.h>
int main()
{
	Queue* myQueue = newQueue();
	for (int i = 0; i < 5; i++)
	{
		enQueue(myQueue, i);
	}
	printQueue(myQueue);
	freeQueue(myQueue);
	printf("%d\n", _CrtDumpMemoryLeaks());
	return 0;
}