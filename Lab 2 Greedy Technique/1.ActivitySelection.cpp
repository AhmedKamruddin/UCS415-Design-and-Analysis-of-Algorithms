#include<iostream>
#include<stack>
using namespace std;

int maxSize=0;
void storeMaxSize(stack<int> s)
{
    if(s.size()>=maxSize)
        maxSize=s.size();
}

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

//Generate all subsets. Find and store maximum size.
void activitySelector1(int start[], int finish[], int k, int n, stack<int> s)
{
    s.push(k+1);
    storeMaxSize(s);
    
    for(int i=0; i<n; i++)
    {
        if(start[i]>=finish[k])
        {
            activitySelector1(start, finish, i, n, s);
        }   
    }
    s.pop();
}

//Generate all subsets. Print only those with maximum size.
void activitySelector2(int start[], int finish[], int k, int n, stack<int> s)
{
    s.push(k+1);
    if(s.size()==maxSize)
        display(s);

    for(int i=0; i<n; i++)
    {
        if(start[i]>=finish[k])
        {
            activitySelector2(start, finish, i, n, s);
        }   
    }
    s.pop();
}


int main()
{
    int n=11;
    int start[n]= {1, 3, 0, 5, 3, 5,  6,  8,  8,  2, 12};
    int finish[n]={4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    stack<int> s;

    for(int i=0; i<n; i++)
        activitySelector1(start, finish, i, n, s);

    for(int i=0; i<n; i++)
        activitySelector2(start, finish, i, n, s);
}