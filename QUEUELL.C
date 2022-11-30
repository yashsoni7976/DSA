#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};
typedef struct node Node;

void enqueue(Node **p, Node **q, int item)
{
	Node *ptr,*trav=*q;
	ptr=(Node *)malloc(sizeof(Node));
	ptr->info=item;
	ptr->next=NULL;
	if(*q==NULL)
	{
		*q=ptr;
		*p=*q;
	}
	else
	{
		trav->next=ptr;
		*q=trav->next;
	}
}

void display(Node *p)
{
	if(p==NULL)
	{
		printf("Empty");
	}
	else
	{
		Node *trav=p;
		while(trav!=NULL)
		{
			printf("%d->",trav->info);
			trav=trav->next;
		}
	}
}

void dequeue(Node **p)
{
	if(*p==NULL)
	{
		printf("UnderFlow");
	}
	else
	{
		Node *ptr,*trav=*p;
		ptr=*p;
		*p=trav->next;
		free(ptr);
	}
}

void main()
{
	Node *front=NULL,*rear=NULL;
	int i, cho, item;
	do
	{
	clrscr();
	display(front);
	printf("\nEnter Choice:");
	printf("\n1.PUSH\n2.POP\nEnter Choice : ");
	scanf("%d",&cho);
	switch(cho)
	{
		case 1: printf("\nEnter Item : ");
			scanf("%d",&item);
			enqueue(&front,&rear,item);
			break;

		case 2: dequeue(&front);
			break;
	}
	}while(cho!=6);
	getch();
}
