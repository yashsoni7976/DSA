#include<stdio.h>
#include<conio.h>
#define MAX 5
int FRONT=-1; int REAR=-1;
int cQueue[MAX];

void enQueue(int item)
{
	if(FRONT==(REAR+1)%MAX)
	{
		printf("\nQueue OverFlow");
		getch();
	}
	else if(FRONT==-1)
	{
		FRONT=0; REAR=0;
		cQueue[REAR]=item;
	}
	else
	{
		REAR=(REAR+1)%MAX;
		cQueue[REAR]=item;
	}
}

void deQueue()
{
	if(FRONT==-1)
	{
		printf("Queue UnderFlow");
	}
	else if((FRONT+1)%MAX==(REAR+1)%MAX)
	{
		FRONT=REAR=-1;
		printf("Empty Queue");
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
		printf("Empty");
		getch();
	}
	else
	{
		for(i=FRONT;;)
		{
			printf("%d ->",cQueue[i]);

			if(i==REAR)
			break;
			i=(i+1)%MAX;
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
