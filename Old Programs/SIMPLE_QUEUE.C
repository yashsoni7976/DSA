#include<stdio.h>
#include<conio.h>
#define MAX 5
int FRONT=-1; int REAR=-1;
int arr[MAX];

void enQueue(int item)
{
	if(REAR==MAX-1)
	{
		printf("\nQueue OverFlow");
		getch();
	}
	else if(FRONT==-1)
	{
		FRONT++;
		REAR++;
		arr[FRONT]=item;
	}
	else
	{
		REAR++;
		arr[REAR]=item;
	}
}

void deQueue()
{
	if(FRONT==-1)
	{
		printf("Queue UnderFlow");
		getch();
	}
	else if(FRONT == REAR && REAR==MAX-1)
	{
		FRONT=-1;
		REAR=-1;
		printf("Queue Got Empty");
		getch();
	}
	else
	{
		FRONT++;
	}
}

void traverse()
{
	int i;
	if(FRONT==-1)
	{
		printf("Empty Queue");
	}
	else
	{
		for(i=FRONT;i<=REAR;i++)
		{
			printf("%d ->",arr[i]);
		}
	}
}

void main()
{
	int item;
	int cho;
	do
	{
		clrscr();
		traverse();
		printf("\nChoose from the Option:-\n");
		printf("\n1. EnQueue\n2. DeQueue\n3. Exit");
		printf("\nEnter Choice : ");
		scanf("%d",&cho);
		switch(cho)
		{
			case 1: printf("Enter Item for Insertion : ");
				scanf("%d",&item);
				enQueue(item);
				break;

			case 2: deQueue();
				break;

		}
	}while(cho!=3);
	getch();
}
