 //   Single Linked List Program   //


#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node
{

int info;
struct Node *next;

};


typedef struct Node Node;
Node *start=NULL;




void insertatbeg(int item)
{

    Node *ptr;
    ptr=(Node*)malloc(sizeof(Node));
    ptr->info=item;
    if (start==NULL)
    {
    start=ptr;
    ptr->next=NULL;
    }

    else
    {
     ptr->next=start;
     start=ptr;
    }

}

void displayLL()
{

	Node*trav;
	trav=start;
	while(trav->next!=NULL)
	{
	clrscr();
		printf("\n %d ->",trav->info);
		trav=trav->next;
	}

}


void main()
{

int item;
char ch;
char choice;
clrscr();

 do
{
fflush(stdin);
printf("Enter your choice: ");
printf("\n 1.Insert at Begining");
printf("\n 2.Show output");
scanf("%d",&choice);

switch(choice)
{


 case 1:
	printf("Enter Item: ");
	scanf("%d",&item);
	insertatbeg(item);
	 break;

 case 2: displayLL();
	  break;

 }

 fflush(stdin);
 printf("\n\n Do you want to continue:");
 scanf("%c",&ch);

 }while(ch=='y'|| ch=='Y');

 getch();

}
