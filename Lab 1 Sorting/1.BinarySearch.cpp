#include<iostream>
using namespace std;

int binarySearchIterative(int a[], int n, int ele)
{
    int first=0;
    int last=n;
    int mid=(first+last)/2;

    while(first<=last)
    {
        if(a[mid]==ele)
        {
            return mid;
        }
        else if(a[mid]>ele)
            {
                last=mid-1;
                mid=(first+last)/2;
            }
        else if(a[mid]<ele)
            {
                first=mid+1;
                mid=(first+last)/2;
            }
    }
    return -1;
}

int binarySearchRecursive(int a[], int first, int last, int ele)
{
    int mid=(first+last)/2;
    if(a[mid]==ele)
        return mid;
    else if(a[mid]>ele)
        return binarySearchRecursive(a, first, mid-1, ele);
    else
        return binarySearchRecursive(a, mid+1, last, ele);
    return -1;
}

int main()
{
    int choice, ele, pos;
    int a[]={0, 1, 2, 4, 5, 6, 7, 8};
    int n=8;
    
    cout<<"1.Iterative 2.Recursive\n";
    cin>>choice;
    cout<<"Enter element to search\n";
    cin>>ele;

    switch(choice)
    {
        case 1:
        {
            pos=binarySearchIterative(a, n, ele);
            break;
        }

        case 2:
        {
            pos=binarySearchRecursive(a, 0, n, ele);
            break;
        }
    }

    if(pos>=0)
        cout<<"Element found at index "<<pos<<endl;
    else
        cout<<"Element not found\n";
}