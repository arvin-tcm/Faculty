#include<stdio.h>
#include<stdlib.h>
struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
};

struct tree* createNewNode(int);
struct tree* insert(struct tree*, int);
int lookup(struct tree*, int);
int size(struct tree*);
int findMaxDepth(struct tree*);
int minValue(struct tree*);
int maxValue(struct tree*);
void printTree(struct tree*);
int isBST(struct tree*);
int isBSTUtil(struct tree*, int, int);
struct tree* destoryTree(struct tree*);
int main()
{
	struct tree* head = NULL;
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
}
struct tree* createNewNode(int input)
{
	struct tree* node = (struct tree*)malloc(sizeof(struct tree));
	node->data = input;
	node->left = NULL;
	node->right = NULL;
	return node;
}
struct tree* insert(struct tree* head, int input)
{
	if (head == NULL)
		return createNewNode(input);
	if (input >= head->data)
		head->right = insert(head->right, input);
	else
		head->left = insert(head->left, input);
	return head;
}

int lookup(struct tree* head, int target)
{
	if (head == NULL) return 0;
	if (target == head->data) return 1;
	if (target >= head->data)
		return lookup(head->right, target);
	else
		return lookup(head->left, target);
}
int size(struct tree* head)
{
	if (head == NULL) return 0;
	return size(head->left) + 1 + size(head->right);
}
int findMaxDepth(struct tree* head)
{
	int rightDepth, leftDepth;
	if (head == NULL) return 0;
	rightDepth = findMaxDepth(head->right);
	leftDepth = findMaxDepth(head->left);
	if (rightDepth >= leftDepth)
		return rightDepth + 1;
	else
		return leftDepth + 1;
}
int minValue(struct tree* head)
{
	struct tree* iterator = head;
	while (iterator->left != NULL)
		iterator = iterator->left;
	return iterator->data;
}
int maxValue(struct tree* head)
{
	struct tree* iterator = head;
	while (iterator->right != NULL)
		iterator = iterator->right;
	return iterator->data;
}

void printTree(struct tree* head)
{
	if (head == NULL) return;
	printTree(head->left);
	printf("%d\n", head->data);
	printTree(head->right);
}
struct tree* destoryTree(struct tree* head)
{
	if (head == NULL) return NULL;
	head->left = destoryTree(head->left);
	head->right = destoryTree(head->right);
	free(head);
	return NULL;
}
int isBST(struct tree* head)
{
	return isBSTUtil(head, minValue(head), maxValue(head));
}
int isBSTUtil(struct tree* head, int min, int max)
{
	if (head == NULL) return 1;
	if (head->data < min || head->data > max) return 0;
	return isBSTUtil(head->left, min, head->data) &&
		isBSTUtil(head->right, head->data, max);
}
