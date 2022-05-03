#include<iostream>
using namespace std;

class knapsack
{
    public:
    static int W;

    int id;
    float profit;
    float weight;
    float ratio;

    knapsack(){}

    knapsack(int id, int profit, int weight)
    {
        this->id=id;
        this->profit=profit;
        this->weight=weight;
        this->ratio=profit/weight;
    }
};

int knapsack::W=60;

int main()
{
    int n=4;
    knapsack kp[n];
    kp[0]=knapsack(1, 280, 40);
    kp[1]=knapsack(2, 100, 10);
    kp[2]=knapsack(3, 120, 20);
    kp[3]=knapsack(4, 120, 24);

    //Sort according to ratio
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(kp[i].ratio<kp[j].ratio)
                swap(kp[i], kp[j]);

    float profit=0;
    int weight=0;

    //Add items to knapsack
    for(int i=0; i<n; i++)
    {
        if(weight+kp[i].weight<kp[0].W)
        {
            cout<<kp[i].id<<" selected\n";
            profit+=kp[i].profit;
            weight+=kp[i].weight;
        }
        else
        {
            cout<<kp[i].id<<" selected\n";
            int remainingSpace=kp[0].W-weight;
            float fractionSelected=remainingSpace/kp[i].weight;
            profit+=fractionSelected*kp[i].profit;
            weight+=fractionSelected*kp[i].weight;
            break;
        }
    }
    cout<<"Profit="<<profit<<" Weight="<<weight<<endl;
}