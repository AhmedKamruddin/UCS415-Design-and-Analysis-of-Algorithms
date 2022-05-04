#include<iostream>
#include<list>
using namespace std;

const int n=6;

list<int> noIncomingEdge(int map[n][n], list<int> s, int visited[])
{
    
    for(int i=0; i<n; i++)
    {
        int flag=1;
        for(int j=0; j<n; j++)
        {
            if(map[j][i]==1 || visited[i]==1)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            visited[i]=1;
            s.push_back(i);
        }
    }
    return s;
}

list<int> topologicalSort(int map[n][n], list<int> s, list<int> l, int visited[])
{
    s=noIncomingEdge(map, s, visited);

    while(!s.empty())
    {
        //Remove a node from s
        int node=s.front();
        s.pop_front();

        //Add the node to tail of l
        l.push_back(node);

        //Remove outgoing edges from the node
        for(int j=0; j<n; j++)
            map[node][j]=0;
        
        //Mark node as visited
        visited[node]=1;

        s=noIncomingEdge(map, s, visited);
    }    
    return l;
    
}

int main()
{
    int map[n][n]={{0, 1, 0, 1, 0, 0},
                   {0, 0, 1, 0, 0, 0},
                   {0, 0, 0, 1, 1, 0},
                   {0, 0, 0, 0, 1, 0},
                   {0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0}};
    int visited[n]={};
    list<int> l; //Sorted elements
    list<int> s; //Set of all nodes with no incoming edges
    
    l=topologicalSort(map, s, l, visited);

    while(!l.empty())
    {
        cout<<l.front()<<" ";
        l.pop_front();
    }
    cout<<endl;
}