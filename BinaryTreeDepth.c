#include<stdio.h>
#include<stdlib.h>
#define n 101

typedef struct Node
{
	int data;
	struct Node *left,*right;
	
}Node,*Tree;


void Create(Tree *T, int root[])
{
	static int index = -1;
	
	if(root[++index]==101)
	{
		*T = NULL;
	}
	else
	{
		*T = (Tree)malloc(sizeof(Node));
		(*T)->data = root[index];
		Create(&(*T)->left,root);
		Create(&(*T)->right,root);
	}
}

void printTree(Tree T)
{
	if(T != NULL)
	{
		printf("%d ",T->data);
		printTree(T->left);
		printTree(T->right);
	}
	else
	{
		printf("null ");
	}
}

int maxDepth(Tree T)
{
	int L=0,R=0;
	
	if(T==NULL)
	{
		return 0;
	}
	else
	{
		L += maxDepth(T->left);
		R += maxDepth(T->right);
		return L>R ? L+1:R+1;
	}
}

int main(int argc, char *argv[])
{
	Tree t;
	int root[]={3,9,n,n,20,15,n,n,7,n,n};
	
	Create(&t,root);
	printTree(t);
	printf("\nMaxDepth:%d",maxDepth(t));
}