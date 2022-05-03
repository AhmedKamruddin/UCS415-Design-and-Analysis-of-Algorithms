#include<iostream>
#include<queue>
using namespace std;

const int n=6;

int isConnected(int a[n][n])
{
    for(int i=0; i<n; i++)
    {
        int flag=0;
        for(int j=0; j<n; j++)
        {
            if(a[j][i]==1)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            return 0;
    }
    return 1;
}

int countOdd(int a[n][n])
{
    int count=0;
    for(int i=0; i<n; i++)
    {
        int degree=0;
        for(int j=0; j<n; j++)
        {
            if(a[i][j]==1)
                degree++;
        }
        if(degree%2==1)
            count++;
    }
    return count;
}


int isEulerian(int a[n][n])
{
    //Check if all non-zero degree vertices are connected
    if(!isConnected(a))
        return -1;
    
    //Count vertices with odd degree
    return countOdd(a);
}

int main()
{
    int a[6][6]={{0, 1, 0, 0, 0, 1},
                 {1, 0, 1, 0, 0, 0},
                 {0, 1, 0, 1, 1, 1},
                 {0, 0, 1, 0, 1, 0},
                 {0, 0, 1, 1, 0, 0},
                 {1, 0, 1, 0, 0, 0}};

    
    switch(isEulerian(a))
    {
        case -1:
        {
            cout<<"Not eulerian\n";
            break;
        }

        case 0:
        {
            cout<<"Eulerian\n";
            break;
        }

        case 2:
        {
            cout<<"Semi eulerian\n";
            break;
        }
    }
}