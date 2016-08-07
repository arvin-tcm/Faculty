#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int ValueT;
struct node
{
	ValueT data;
	struct node* left;
	struct node* right;
};
typedef struct node Node;

Node* createNewNode(ValueT);
Node* insert(Node*, ValueT);
int lookup(Node*, ValueT);
int size(Node*);
int findMaxDepth(Node*);
ValueT minValue(Node*);
ValueT maxValue(Node*);
void printTree(Node*);
int isBST(Node*);
int isBSTUtil(Node*, ValueT, ValueT);
Node* destoryTree(Node*);
