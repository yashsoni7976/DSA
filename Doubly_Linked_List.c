#include<stdio.h>
#include<conio.h>

/*
	Structure of Linked List
*/
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
typedef struct node Node;

/*
	Insert From Beginning
*/
void insertBeg(Node **s, int item)
{
	Node *ptr;
	Node *temp=*s;
	ptr=(Node *)malloc(sizeof(Node));
	ptr->prev=NULL;
	ptr->data=item;
	if(*s==NULL)
	{
		*s=ptr;
		ptr->next=NULL;
	}
	else
	{
		ptr->next=*s;
		temp->prev=ptr;
		*s=ptr;
	}
}

/*
	Insert at Last
*/
void insertLast(Node **s, int item)
{
	Node *ptr;
	ptr=(Node *)malloc(sizeof(Node));
	ptr->prev=NULL;
	ptr->data=item;
	if(*s==NULL)
	{
		*s=ptr;
		ptr->next=NULL;
	}
	else
	{
		Node *temp=*s;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=ptr;
		ptr->prev=temp;
		ptr->next=NULL;
	}
}

/*
	Insert Specific Postion
*/
void insertPos(Node **s, int item, int pos)
{
	Node *ptr,*temp;
	Node *trav=*s;
	int i;
	ptr=(Node *)malloc(sizeof(Node));
	ptr->data=item;
	if(*s==NULL)
	{
		*s=ptr;
		ptr->next=NULL;
	}
	else
	{
		for(i=1;i<pos-1;i++)
		{
			trav=trav->next;
		}
		temp=trav->next;
		ptr->next=trav->next;
		ptr->prev=trav;
		trav->next=ptr;
		temp->prev=ptr;
	}
}

/*
	Delete from Beginning
*/
void deleteBeg(Node **s)
{
	if(*s==NULL)
	{
		printf("Empty List");
	}
	else
	{
		Node *ptr=*s;
		*s=(*s)->next;
		(*s)->prev=NULL;
		free(ptr);
	}
}

/*
	Delete from Beginning
*/
void deleteLast(Node **s)
{
	Node *trav,*ptr;
	trav=*s;
	if(*s==NULL)
	{
		printf("Empty List");
	}
	else
	{
		while(trav->next!=NULL)
		{
			trav=trav->next;
		}
		ptr=trav->prev;
		ptr->next=NULL;
		free(trav);
	}
}

/*
	Delete Specific Postion
*/
void deletePos(Node **s, int pos)
{
	Node *ptr,*temp;
	Node *trav=*s;
	int i;
	if(*s==NULL)
	{
		printf("Empty List");
	}
	else
	{
		for(i=1;i<pos;i++)
		{
			trav=trav->next;
		}
		temp=trav->next;
		temp->prev=trav->prev;
		temp=trav->prev;
		temp->next=trav->next;
		free(trav);
	}
}

/*
	Function for Display
*/
void display(Node *s)
{
	Node *temp=s;
	if(s==NULL)
	{
		printf("\nEMPTY");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d <->",temp->data);
			temp=temp->next;
		}
	}
}

/*
	Main Function
*/
void main()
{
	Node *start=NULL;
	int cho, item, pos;
	do
	{
		clrscr();
		display(start);
		printf("\nChoose from the Options :-");
		printf("\n1. Insert at Beginning\n2. Insert at Last \n3. Insert Specific Position");
		printf("\n4. Delet from Beginning\n5. Delete from Last \n6. Delete Specific Position");
		printf("\nEnter Option: ");
		scanf("%d",&cho);
		switch(cho)
		{
			case 1: printf("\nEnter Item : ");
				scanf("%d",&item);
				insertBeg(&start,item);
				break;
			case 2: printf("\nEnter Item : ");
				scanf("%d",&item);
				insertLast(&start,item);
				break;
			case 3: printf("\nEnter Item and Position : ");
				scanf("%d %d",&item,&pos);
				insertPos(&start,item,pos);
				break;
			case 4: deleteBeg(&start);
				break;
			case 5: deleteLast(&start);
				break;
			case 6: printf("\nEnter Position : ");
				scanf("%d",&pos);
				deletePos(&start, pos);
				break;
		}
	}while(cho!=9);
}

