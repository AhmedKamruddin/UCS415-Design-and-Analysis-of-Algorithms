#include<iostream>
#include<stack>
using namespace std;
const int n=5;

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

int colorOfConnectedNode(int j, int color, stack<int> s)
{
	int val=-1;
	stack<int> temp;
	while(s.size()>j)
	{
		temp.push(s.top());
		s.pop();
	}
	val=temp.top();
	while(!temp.empty())
	{
		s.push(temp.top());
		temp.pop();
	}
	
	return val;
}

int anyNeighborHasSameColor(int a[n][n], int color, stack<int> s)
{
    int node=s.size();
    for(int j=0; j<n; j++)
    {
        if(a[node][j]==1 && j<s.size() && color==colorOfConnectedNode(j, color, s))
        {
            return 1;
        }
    }
    return 0;

}

void displayMinNoOfColors(stack<int> s, int m)
{
	int count=0;
	int x[m]={};

	while(!s.empty())
	{
		x[s.top()]=1;
		s.pop();
	}

	for(int i=0; i<m; i++)
		count+=x[i];
		
	cout<<"Min colors: "<<count<<endl;
}

void graphColoring(int a[n][n], int color, int m, stack<int> s)
{
    s.push(color);

    if(s.size()==n)
    {
        display(s);
        displayMinNoOfColors(s, m);
		exit(0);
    }

    for(int color=0; color<m; color++)
    {
        if(anyNeighborHasSameColor(a, color, s))
           continue; 
        
        graphColoring(a, color, m, s);
    }
    s.pop();
}

int main()
{
    int a[n][n]={{0, 0, 1, 0, 1},
				 {0, 0, 1, 1, 1},
				 {1, 1, 0, 1, 0},
				 {0, 1, 1, 0, 1},
				 {1, 1, 0, 1, 0}};
	int m=5;
    stack<int> s;

    for(int i=0; i<m; i++)
        graphColoring(a, i, m, s);
}