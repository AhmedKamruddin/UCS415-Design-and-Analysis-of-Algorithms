#include<iostream>
#include<list>
using namespace std;

const int n=6;

list<int> noIncomingEdge(int map[n][n], list<int> s)
{
    
    for(int i=0; i<n; i++)
    {
        int flag=1;
        for(int j=0; j<n; j++)
        {
            if(map[j][i]==1 || map[j][i]==-1 || map[j][i]==-2)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            //cout<<i<<" has no incoming edges\n";
            for(int j=0; j<n; j++)
                map[j][i]=-2;
            
            s.push_back(i);
        }
    }
    return s;
}

list<int> topologicalSort(int map[n][n], list<int> s, list<int> l)
{
    s=noIncomingEdge(map, s);

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
        
        //Remove the node from map
        for(int i=0; i<n; i++)
            map[i][node]=-1;
    
        s=noIncomingEdge(map, s);
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

    list<int> l; //Sorted elements
    list<int> s; //Set of all nodes with no incoming edges
    
    l=topologicalSort(map, s, l);

    while(!l.empty())
    {
        cout<<l.front()<<" ";
        l.pop_front();
    }
    cout<<endl;
}