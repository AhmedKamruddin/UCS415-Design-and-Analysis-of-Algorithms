#include<iostream>
#include<stack>
using namespace std;

void subsetSum(int a[], int k, int n, int d, int sum, int rem, int x[])
{
    x[k]=1;
    if(sum+a[k]==d)
    {
        for(int i=0; i<n; i++)
            if(x[i])
                cout<<a[i]<<" ";
        cout<<endl;
        return;
    }

    else if(sum+a[k]+a[k+1]<=d)
        subsetSum(a, k+1, n, d, sum+a[k], rem-a[k], x);

    if( sum+rem-a[k]>=d && sum+a[k+1]<=d)
    {
        x[k]=0;
        subsetSum(a, k+1, n, d, sum, rem-a[k], x);
    }
    
}

int main()
{
    int a[]={3, 5, 6, 7};
    int n=sizeof(a)/sizeof(*a);
    stack<int> s;
    int d=15;
    int sum=0;

    int rem=0;
    for(int j=0; j<n; j++)
        rem+=a[j];
    
    int x[n]={};
    subsetSum(a, 0, n, d, sum, rem, x);
}