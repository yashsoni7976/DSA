#include<stdio.h>

int deci2binary(int x)
{
    int temp;
    if(x==0)
        return 0;
    temp=x%2;
    deci2binary(x / 2);
    printf("%d",temp);
}

int main()
{
    int i;
    scanf("%d",&i);
    deci2binary(i);
    return 0;
}
