#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
typedef struct node Queue;
Queue* queue_push(Queue*, int);
Queue* queue_pop(Queue*);
int queue_peak(Queue*);
void queue_destroy(Queue*);
void queue_print(Queue*);

int main() 
{
	Queue* head = NULL;
	int value;
	for (int i = 0; i < 10; i++)
		head = queue_push(head, i * 10);
	queue_print(head);
	for (int i = 0; i < 3; i++)
	{
		printf("pop function called. value = %2d\n", queue_peak(head));
		head = queue_pop(head);
	}
	queue_print(head);
	queue_destroy(head);
	return 0;
}

Queue* queue_push(Queue* headPtr, int data)
{
	Queue* newNode = (Queue*)malloc(sizeof(Queue));
	newNode->data = data;
	newNode->next = headPtr;
	return newNode;
}

Queue* queue_pop(Queue* headPtr)
{
	Queue* temp = headPtr;
	if (temp == NULL) return NULL;
	if (temp->next == NULL)
	{
		free(temp);
		return NULL;
	}
	while (temp->next->next != NULL)
		temp = temp->next;

	free(temp->next);
	temp->next = NULL;
	return headPtr;
}

int queue_peak(Queue* headPtr)
{
	while (headPtr->next != NULL)
	{
		headPtr = headPtr->next;
	}
	return headPtr->data;
}

void queue_destroy(Queue* headPtr)
{
	Queue* temp;
	while (headPtr)
	{
		temp = headPtr->next;
		free(headPtr);
		headPtr = temp;
	}
}

void queue_print(Queue* headPtr)
{
	printf("\nHead Pointer is pointing to address: %d\n", headPtr);
	while (headPtr != NULL)
	{
		printf("data: %3d\taddress: %9d\n", headPtr->data, headPtr);
		headPtr = headPtr->next;
	}
	printf("End of the Queue print\n\n");
}