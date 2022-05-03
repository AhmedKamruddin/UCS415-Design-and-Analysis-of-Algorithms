#include<iostream>
using namespace std;

bool Place(int x[], int k, int i)
{
    for(int j=0; j<k; j++)
    {
        if( x[j]==i || (abs(x[j]-i)==abs(j-k)) )
            return false;
    }   

    return true;

}

int NQueens(int x[], int k, int n)
{
    for(int i=0; i<n; i++)
    {
        if(Place(x, k, i))
        {
            x[k]=i;
            if(k==n-1)
                {
                    for(int index=0; index<n; index++)
                        cout<<x[index]+1<<" ";
                    
                    cout<<endl;
                }
            else
                NQueens(x, k+1, n);
        }
    }
}

int main()
{
    int n;
    cout<<"Enter value of n\n";
    cin>>n;

    int x[n];

    NQueens(x, 0, n);
}