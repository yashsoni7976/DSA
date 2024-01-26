#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;
};

typedef struct node Node;

void insert(Node **q, int item)
{
	Node *ptr;
	Node *trav;
	ptr=(Node *)malloc(sizeof(Node));
	ptr->data=item;
	if(*q==NULL)
	{
		printf("Empty List");
		*q=ptr;
	}
	else
	{
		trav=*q;
		while(trav->next!=NULL)
		{
			trav=trav->next;
		}
		trav->next=ptr;
	}
	ptr->next=NULL;
}

void display(Node *q)
{
	Node *trav=q;
	if(trav==NULL)
	{
		printf("Empty");
	}
	else
	{
		while(trav!=NULL)
		{
			printf("%d ->",trav->data);
			trav=trav->next;
		}
	}
}        =

void merge(Node **q1,Node **q2)
{
	Node *trav=*q1;
	while(trav->next!=NULL)
	{
		trav=trav->next;
	}
	trav->next=*q2;
	free(q2);
}

void main()
{
	Node *s1=NULL, *s2=NULL;
	int item, cho;
	clrscr();
	do{
	clrscr();
	printf("\nEnter Choice : ");
	printf("\n1. Insert Element in First Node \n2.Insert Element in Second Node");
	printf("\n3. Merge Both\n 9.Exit");
	scanf("%d",&cho);
	switch(cho)
	{
		case 1: clrscr();
			display(s1);
			printf("\nEnter Item : ");
			scanf("%d",&item);
			insert(&s1,item);
			break;

		case 2: clrscr();
			display(s2);
			printf("\nEnter Item : ");
			scanf("%d",&item);
			insert(&s2,item);
			break;

		case 3: printf("Merging Two Linked List\n");
			merge(&s1,&s2);
			display(s1);
			getch();
			break;
	 }
	 }while(cho!=9);
	getch();
}
