#include<stdio.h>
#include<conio.h>
#define MAX 20
/*
	Linear Seacrch Algorithm for Unordered Array
*/
int LS_Unorder(int A[], int n, int item)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(item == A[i])
		{
			return i;
		}
	}
	return -1;
}
/*
	Linear Seacrch Algorithm for Ordered Array
*/
int LS_Order(int A[], int n, int item)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(item == A[i])
			return i;
		else if(item < A[i])
			return -1;
	}
}

void main()
{
	int pos, i, cho, arr[MAX],arr1[MAX], n, item;
	clrscr();
	printf("\nEnter Size of Array : ");
	scanf("%d", &n);

	printf("\nEnter Unordered Array : ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	printf("\nEnter Ordered Array : ");
	for(i=0;i<n;i++)
		scanf("%d",&arr1[i]);

	do
	{       clrscr();
		printf("\nUnordered Array : ");
		for(i=0;i<n;i++)
			printf("%d ",arr[i]);

		printf("\nOrdered Array : ");
		for(i=0;i<n;i++)
			printf("%d ",arr1[i]);
		printf("\nChoose Option:-\n 1.Un-Ordered Pair\n 2.Ordered Pair\nEnter Option : ");
		scanf("%d",&cho);
		switch(cho)
		{
			case 1: printf("Enter item for searching : ");
				scanf("%d",&item);
				pos=LS_Unorder(arr,n,item);
				break;

			case 2: printf("Enter item for searching : ");
				scanf("%d",&item);
				pos=LS_Order(arr,n,item);
				break;
		}
		if(pos==-1)
			printf("\n404 NOT FOUND");
		else
			printf("Position is %d",pos+1);
		getch();
	}while(cho!=9);
}
