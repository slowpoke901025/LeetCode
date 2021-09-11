#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node
{
	char data;
	struct node *next;
}*Node;

typedef struct
{
	Node head;
	Node tail;
}list,*List;

void initList(List *L)
{
	*L = (List)malloc(sizeof(list));
	(*L)->head = (*L)->tail = NULL;	
}

void insertList(List L,char data)
{
	Node P = (Node)malloc(sizeof(node));
	if(L->head==NULL)
	{
		L->head = L->tail = P;
	}
	else
	{
		L->tail->next = P;
		L->tail = P;
	}
	P->data = data;
	P->next = NULL;
}

void printList(List L)
{
	Node P = L->head;
	while(P!=NULL)
	{
		printf("%c -> ",P->data);
		P = P->next;
	}
	printf("NULL\n");
}
void createList(List L, int num)
{
	for(int i=0;i<num;i++)
	{
		char data = rand()%('Z'-'A'+1)+'A';
		insertList(L,data);
	}
	printList(L);
}

void reverse(Node N,Node Last)
{
	if(N)
	{
		reverse(N->next, N);
		N ->next = Last;
	}
}

void reverseList(List L)
{
	reverse(L->head,NULL);
	
	Node P = L->head;
	L->head = L->tail;
	L->tail = P;
	
	printList(L);
}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	List L;
	initList(&L);
	createList(L,5);
	reverseList(L);
	createList(L,5);
	reverseList(L);
}