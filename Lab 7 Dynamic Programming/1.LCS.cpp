#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int n1, n2;
    //char s1[20], s2[20];
    //cout<<"Enter two strings\n";
    //cin>>s1>>s2;
    char s1[]="ABCBDAB";
    char s2[]="BDCABA";
    n1=1+strlen(s1);
    n2=1+strlen(s2);

    int c[n1][n2];
    
    char arrow[n1][n2];
    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<n2; j++)
        {
            arrow[i][j]='-';
        }
    }

    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<n2; j++)
        {
            //Case 1
            if(i==0 || j==0)
            {
                c[i][j]=0;
            }
            
            //Case 2
            else if(i>0 && j>0 && s1[i-1]==s2[j-1])
            {
                c[i][j]=c[i-1][j-1]+1;
                arrow[i][j]='d';
            }

            //Case 3
            else if(i>0 && j>0 && s1[i-1]!=s2[j-1])
            {
                c[i][j]=max(c[i-1][j], c[i][j-1]);

                if(c[i-1][j] >= c[i][j-1])
                {
                    arrow[i][j]='u';
                }
                else
                {
                    arrow[i][j]='l';
                }
            }
        }
    }

    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<n2; j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<n2; j++)
        {
            cout<<arrow[i][j]<<" ";
        }
        cout<<endl;
    }

    int i=n1-1;
    int j=n2-1;
    char final[ n1>n2?n1:n2 ];
    int k=0;
    while(c[i][j]!=0)
    {
        switch(arrow[i][j])
        {
            case 'u':
            {
                i=i-1;
            }

            case 'l':
            {
                j=j-1;
            }

            case 'd':
            {
                cout<<"Diagonal case: "<<s1[i-1]<<endl;
                final[k++]=s1[i-1];
                i=i-1;
                j=j-1;
            }
        }
    }

    while(k>0)
    {
        cout<<final[--k];
    }
}