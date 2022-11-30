#include<stdio.h>
#include<conio.h>
#define MAX 10

int stack[MAX];
int tos1=-1;
int tos2=MAX;
void push1(int);
int pop1();
void display1();
void push2(int);
int pop2();
void display2();

void main()
{
	int item;
	int cho,stacho;
	do
	{       clrscr();
		printf("\nChoice");
		printf("\n1.STACK 1\n2.STACK 2\n3.DISPLAY\n4.EXIT");
		scanf("%d",&stacho);
		switch(stacho)
		{
		case 1:
		printf("\n1. Push\n2. POP\n");
		scanf("%d",&cho);
		switch(cho)
		{
			case 1: printf("Enter Element to the Inserted int the stack");
				scanf("%d",&item);
				push1(item);
				getch();
				break;
			case 2: pop1();
				getch();
				break;
			default : printf("\nInvalid");
				  break;
		}
		break;

		case 2:
		printf("\n1. Push\n2. POP\n");
		scanf("%d",&cho);
		switch(cho)
		{
			case 1: printf("Enter Element to the Inserted int the stack");
				scanf("%d",&item);
				push2(item);
				getch();
				break;
			case 2: pop2();
				getch();
				break;

			default : printf("\nInvalid");
				  break;
		}
		break;
		case 3: printf("\nDisplaying Item\n");
				display1();
				printf(" ");
				display2();
				getch();
				break;
		}
	}while(stacho!=4);
	getch();
}

void push2(int i)
{
	if(tos2==-1 || tos2==tos1+1)
	{
		printf("\n Overflow");
	}
	else
	{
		tos2--;
		stack[tos2]=i;
	}
}

int pop2()
{
	if(tos2==MAX-1)
	{
		printf("\n Underflow");
	}
	else
	{
		tos2++;
		printf("\nItem Deleted");

	}

}

void display2()
{
	int i;
	for(i=MAX-1;i>=tos2;i--)
	{
		printf("%d <- ",stack[i]);
	}
	getch();
}

void push1(int i)
{
	if(tos1==tos2-1)
	{
		printf("\n Overflow");
	}
	else
	{
		tos1++;
		stack[tos1]=i;
	}
}

int pop1()
{
	if(tos1==-1)
	{
		printf("\n Underflow");
	}
	else
	{
		tos1--;
		printf("\nItem Deleted");

	}

}

void display1()
{
	int i;
	for(i=0;i<=tos1;i++)
	{
		printf("%d -> ",stack[i]);
	}
	getch();
}