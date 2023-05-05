#include<stdio.h>

int max(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
//Recursive Approach
int knapsack(int pro[],int wt[], int n, int W){
    if(n==0 || W==0){
        return 0;
    }
    
    if(W<wt[n-1]){
        return knapsack(pro,wt[n-1],n,W);
    }
    else{
        return max(pro[n-1]+knapsack(pro,W-wt[n-1],n-1,W), knapsack(pro,wt,n,W));
    }
}
//Loop Approach
int knapsack(int pro[],int wt[], int n, int W){
    int i, w;
    int k[n+1][W+1];
    for(i=0;i<=n;i++){
        for(w=0;w<=W;w++){
            if(i==0 || w==0){
                k[i][w]=0;
            }
            else if(wt[i-1]<=W){
                k[i][w]=max(pro[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
            }
            else{
                k[i][w]=k[i-1][w];
            }
        }
    }
    return k[i][w];
}

int main(){
    int w,n,i,j,pro[10], wt[10];
    int max_wt;
    
    printf("Enter Number of Items you want to Select : ");
    scanf("%d",&n);
    
    printf("\nEnter Profit : ");
    for(i=0;i<n;i++)
        scanf("%d",&pro[i]);
    
    printf("\nEnter Weight : ");
    for(i=0;i<n;i++)
        scanf("%d",&wt[i]);

    printf("\nEnter Maximum Weight of Sack : ");
    scanf("%d",&w);

    printf("\n\nMaximum weight of Sack : %d",w);
    printf("\nProfit : ");
    for(i=0;i<n;i++)
        printf("%d\t",pro[i]);
    printf("\nWeight : ");
    for(i=0;i<n;i++)
        printf("%d\t",pro[i]);
    
    max_wt=knapsack(pro,wt,n,w);

    printf("%d",max_wt);
    return 0;
}
