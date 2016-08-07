#include "BinarySearchTree.h"

Node* createNewNode(ValueT input)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = input;
	node->left = NULL;
	node->right = NULL;
	return node;
}
Node* insert(Node* treeHead, ValueT input)
{
	if (treeHead == NULL)
		return createNewNode(input);
	if (input >= treeHead->data)
		treeHead->right = insert(treeHead->right, input);
	else
		treeHead->left = insert(treeHead->left, input);
	return treeHead;
}
int lookup(Node* treeHead, ValueT target)
{
	if (treeHead == NULL) return 0;
	if (target == treeHead->data) return 1;
	if (target >= treeHead->data)
		return lookup(treeHead->right, target);
	else
		return lookup(treeHead->left, target);
}
int size(Node* treeHead)
{
	if (treeHead == NULL) return 0;
	return size(treeHead->left) + 1 + size(treeHead->right);
}
int findMaxDepth(Node* treeHead)
{
	int rightDepth, leftDepth;
	if (treeHead == NULL) return 0;
	rightDepth = findMaxDepth(treeHead->right);
	leftDepth = findMaxDepth(treeHead->left);
	if (rightDepth >= leftDepth)
		return rightDepth + 1;
	else
		return leftDepth + 1;
}
ValueT minValue(Node* treeHead)
{
	Node* iterator = treeHead;
	while (iterator->left != NULL)
		iterator = iterator->left;
	return iterator->data;
}
ValueT maxValue(Node* treeHead)
{
	Node* iterator = treeHead;
	while (iterator->right != NULL)
		iterator = iterator->right;
	return iterator->data;
}
void printTree(Node* treeHead)
{
	if (treeHead == NULL) return;
	printTree(treeHead->left);
	printf("%d\n", treeHead->data);
	printTree(treeHead->right);
}
int isBST(Node* treeHead)
{
	return isBSTUtil(treeHead, minValue(treeHead), maxValue(treeHead));
}
int isBSTUtil(Node* treeHead, ValueT min, ValueT max)
{
	if (treeHead == NULL) return 1;
	if (treeHead->data < min || treeHead->data > max) return 0;
	return isBSTUtil(treeHead->left, min, treeHead->data) &&
		isBSTUtil(treeHead->right, treeHead->data, max);
}
Node* destoryTree(Node* treeHead)
{
	if (treeHead == NULL) return NULL;
	treeHead->left = destoryTree(treeHead->left);
	treeHead->right = destoryTree(treeHead->right);
	free(treeHead);
	return NULL;
}
