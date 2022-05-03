#include<iostream>
#include<stack>
using namespace std;

int const n=4;

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

void hamiltonian(int a[n][n], int k, int visited[], stack<int> s)
{
    visited[k]=1;
    s.push(k);

    if(s.size()==n)
        display(s);

    for(int i=0; i<n; i++)
    {
        if(a[k][i]==1 && visited[i]==0)
            hamiltonian(a, i, visited, s);
    }
    visited[k]=0;
    s.pop();
}

int main()
{
    int a[n][n]={{0, 1, 0, 0},
                 {1, 0, 1, 1},
                 {0, 1, 0, 1},
                 {0, 1, 1, 0}};
    int visited[n]={};
    stack<int> s;

    for(int i=0; i<n; i++)
        hamiltonian(a, i, visited, s);
}