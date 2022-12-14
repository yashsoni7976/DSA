#include<stdio.h>
#include<conio.h>
#define MAX 20

int* BubbleSort(int A[], int n)
{
	int i, j, temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(A[j]>A[j+1])
			{
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
	return A;
}

void main()
{
	int i, arr[MAX], n, *p;
	clrscr();
	printf("\nEnter Size of Array : ");
	scanf("%d", &n);

	printf("\nEnter Un-Ordered Array : ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	clrscr();
	printf("\nBubble Sorted Array : ");
	p=BubbleSort(arr,n);
	for(i=0;i<n;i++)
		printf("%d ",p[i]);

	getch();
}