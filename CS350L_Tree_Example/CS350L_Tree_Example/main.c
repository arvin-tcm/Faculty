#include"BinarySearchTree.h"
#include<crtdbg.h>
int main()
{
	Node* head = NULL;
	head = insert(head, 10);
	head = insert(head, 5);
	head = insert(head, 13);
	head = insert(head, 11);
	head = insert(head, 12);
	head = insert(head, 7);
	head = insert(head, 9);
	head = insert(head, 8);
	head = insert(head, 2);
	head = insert(head, 16);
	printTree(head);
	printf("Max value: %d\n", maxValue(head));
	printf("Min value: %d\n", minValue(head));
	printf("find value: %d\n", lookup(head, 8));
	printf("find value: %d\n", lookup(head, 1));
	printf("size: %d\n", size(head));
	printf("Depth: %d\n", findMaxDepth(head));
	head = destoryTree(head);
	printf("Memory Leak: %d\n", _CrtDumpMemoryLeaks());
}