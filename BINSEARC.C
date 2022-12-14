#include<stdio.h>
#include<conio.h>
#define MAX 20
/*
	Linear Seacrch Algorithm for Unordered Array
*/
int BS(int A[], int n, int item)
{
	int l=0,h=n-1,mid;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(item == A[mid])
		{
			return mid;
		}
		else if(item<A[mid])
		{
			h=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return -1;
}

void main()
{
	int pos, i, arr[MAX], n, item;
	clrscr();
	printf("\nEnter Size of Array : ");
	scanf("%d", &n);

	printf("\nEnter Ordered Array : ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	clrscr();
	printf("\nOrdered Array : ");

	for(i=0;i<n;i++)
		printf("%d",arr[i]);

	printf("\nEnter item for searching : ");
	scanf("%d ",&item);
	pos=BS(arr,n,item);

	if(pos==-1)
		printf("\n404 NOT FOUND");
	else
		printf("Position is %d",pos+1);
	getch();
}