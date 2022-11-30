#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};
typedef struct node Node;

void insertion(Node **q, int item)
{
	Node *ptr;
	ptr=(Node *)malloc(sizeof(Node));
	ptr->info=item;
	if(*q==NULL)
	{
		printf("Underflow\n");
		*q=ptr;
	}
	else
	{
		ptr->next=*q;
		*q=ptr;
	}
}

void display(Node *q)
{
	if(q==NULL)
	{
		printf("Empty");
	}
	else
	{
		Node *trav=q;
		while(trav->next!=NULL)
		{
			printf("%d->",trav->info);
			trav=trav->next;
		}
	}
}

void pop(Node **q)
{
	if(*q==NULL)
	{
		printf("UnderFlow");
	}
	else
	{
		Node *ptr,*trav=*q;
		ptr=*q;
		*q=trav->next;
		free(ptr);
	}
}

void main()
{
	Node *top;
	int i, cho, item;
	do
	{
	clrscr();
	display(top);
	printf("\nEnter Choice:");
	printf("\n1.PUSH\n2.POP\nEnter Choice : ");
	scanf("%d",&cho);
	switch(cho)
	{
		case 1: printf("\nEnter Item : ");
			scanf("%d",&item);
			insertion(&top,item);
			break;

		case 2: pop(&top);
			break;
	}
	}while(cho!=6);
	getch();
}
