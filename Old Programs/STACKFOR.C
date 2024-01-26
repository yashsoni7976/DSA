#include<stdio.h>
#include<conio.h>
#define MAX 5

int stack[MAX];
int tos=-1;
void push(int);
int pop();
void display();

void main()
{
	int item;
	int cho;
	do
	{       clrscr();
		printf("\nChoice");
		printf("\n1. Push\n2. POP\n3. Display\n4. Exit");
		scanf("%d",&cho);
		switch(cho)
		{
			case 1: printf("Enter Element to the Inserted int the stack");
				scanf("%d",&item);
				push(item);
				getch();
				break;
			case 2: pop();
				getch();
				break;
			case 3: printf("\nDisplaying Item\n");
				display();
				getch();
				break;
			default : printf("\nInvalid");
				  break;
		}
	}while(cho!=4);
	getch();
}

void push(int i)
{
	if(tos==MAX-1)
	{
		printf("\n Overflow");
	}
	else
	{
		tos++;
		stack[tos]=i;
	}
}

int pop()
{
	if(tos==-1)
	{
		printf("\n Underflow");
	}
	else
	{
		tos--;
		printf("\nItem Deleted");

	}

}

void display()
{
	int i;
	for(i=0;i<=tos;i++)
	{
		printf("%d -> ",stack[i]);
	}
	getch();
}