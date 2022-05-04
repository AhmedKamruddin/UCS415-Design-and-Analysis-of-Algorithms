#include<iostream>
#include<stack>
using namespace std;

const int n=6;

void display(stack<int> s)
{
    stack<int> temp;
    while(!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }
    while(!temp.empty())
    {
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<endl;
}

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
        {
            cout<<"Graph isnt connected\n";
            exit(0);
        }
    }
    return 1;
}

int eulerian(int a[n][n], int k, stack<int> s, int visited[n][n], int edges)
{
    s.push(k);
    if(s.size()==edges+1)
        display(s);
    for(int i=0; i<n; i++)
    {
        if(a[k][i]==1 && visited[k][i]==0)
        {
            visited[k][i]=1;
            visited[i][k]=1;
            eulerian(a, i, s, visited, edges);
            visited[k][i]=0;
            visited[i][k]=0;
        }
    }
    s.pop();
}

int main()
{
    int a[n][n]={{0, 1, 0, 0, 0, 1},
                 {1, 0, 1, 0, 0, 0},
                 {0, 1, 0, 1, 1, 1},
                 {0, 0, 1, 0, 1, 0},
                 {0, 0, 1, 1, 0, 0},
                 {1, 0, 1, 0, 0, 0}};
    int visited[n][n]={};
    stack<int> s;

    int edges=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(a[i][j]==1)
                edges++;
        }
    }
    edges=edges/2;

    isConnected(a);

    for(int i=0; i<n; i++)
        eulerian(a, i, s, visited, edges);

}
/*
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
*/