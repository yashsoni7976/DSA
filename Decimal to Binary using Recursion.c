#include<iostream>
using namespace std;

int deci2binary(int x)
{
    if(x==0)
        return 0;
    int temp=x%2;
    deci2binary(x / 2);
    cout<<temp;
}

int main()
{
    int i;
    cin>>i;
    deci2binary(i);
    return 0;
}
