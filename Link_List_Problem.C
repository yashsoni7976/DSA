//WAP to Implement Link list with following operation
// 1. Delete specific Item
// 2. Insert Element in Ascending Order
#include<stdio.h>
#include<conio.h>

struct node
{
	int info;
	struct node *next;
};
typedef struct node Node;

void insert_pos(Node **q, int item)
{
	Node *ptr;
	Node *trav,*pos=*q;
	ptr=(Node *)malloc(sizeof(Node));
	ptr->info=item;
	if(*q==NULL)
	{
		printf("\nFirst Element is Entered");
		*q=ptr;
		ptr->next=NULL;
	}
	else if(item < (pos->info))
	{
		ptr->next=*q;
		*q=ptr;
	}
	else if(pos->next==NULL && (pos->info) < item)
	{
		pos->next=ptr;
		ptr->next=NULL;
	}
	else
	{
		trav=pos->next;
		while(item > (trav->info) && (trav)!=NULL)
		{
			trav=trav->next;
			pos=pos->next;
		}
		ptr->next=pos->next;
		pos->next=ptr;
	}
}

void delete_pos(Node **q,int item)
{
	Node *ptr;
	Node *trav,*pos;
	trav=*q;
	pos=trav->next;
	if(*q==NULL)
	{
		printf("Underflow");
	}
	else
	{
		if((trav->info)==item)
		{
			ptr=trav;
			*q=trav->next;
			free(ptr);
		}
		else
		{
			while(item!=(pos->info) && (pos->next)!=NULL)
			{
				trav=trav->next;
				pos=pos->next;
			}
			if(pos->next==NULL)
			{
				free(pos);
				trav->next=NULL;
			}
			else
			{
				ptr=pos;
				trav->next=pos->next;
				free(ptr);
			}
		}
	}
}

void display(Node *q)
{
	Node *trav;
	trav=q;
	if(q==NULL)
	{
		printf("Underflow");
	}
	else
	{
	while(trav!=NULL)
	{
		printf("%d<-",trav->info);
		trav=trav->next;
	}
	}
}

void main()
{
	Node *start=NULL;
	int cho,item;
	do
	{
	clrscr();
	display(start);
	printf("\nEnter Choice :-");
	printf("\n1. Insertion\n2. Deletion\nEnter Choice : ");
	scanf("%d",&cho);
	switch(cho)
	{
		case 1: printf("Enter Item : ");
			scanf("%d",&item);
			insert_pos(&start,item);
			break;
		case 2: printf("Enter Item : ");
			scanf("%d",&item);
			delete_pos(&start,item);
			break;
	}
	}while(cho!=6);
}
