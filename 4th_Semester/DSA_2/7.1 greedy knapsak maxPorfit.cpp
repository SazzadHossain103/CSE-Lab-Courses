// greedy algorithm

#include<bits/stdc++.h>
using namespace std;
// greedy algorithm
int main()
{
    int job[5] = {1,2,3,4,5};
    int profit[5] = {20,38,16,10,30};
    int date[5] = {2,3,2,1,3};
    int slot[3] ={0,0,0};

    for(int i=0; i<4; i++)
    {
        for(int j=i+1; j<5; j++)
        {
            if(profit[i]<profit[j])
            {
                swap(profit[i],profit[j]);
                swap(job[i],job[j]);
                swap(date[i],date[j]);
            }
        }
    }
    int s=0;
    for(int i=0; i<5; i++)
    {
        for(int j=date[i]-1; j>=0; j--){
            if(slot[j]==0){
                    slot[j]=job[i];
                    s+=profit[i];
                    break;
            }

        }
    }
    for(int i=0; i<3; i++){
        cout<<slot[i]<<" ";
    }
    cout<<endl;
    cout<<"Max profit = "<<s<<endl;

}




// greedy algorithm
void knapsak()
{

    int weight[5] = {10,14,12,3,5};
    int profit[5] = {5,4,10,15,2};
    int capacity = 30;

    for(int i=0; i<4; i++)
    {
        for(int j=i+1; j<5; j++)
        {
            if(profit[i]<profit[j])
            {
                swap(profit[i],profit[j]);
                swap(weight[i],weight[j]);
            }
        }
    }
    int s=0;
    for(int i=0; i<5; i++)
    {
        if(capacity>weight[i])
        {
            s+=profit[i]*weight[i];
            capacity-=weight[i];
        }
        else
        {
            s+=(profit[i]*capacity);
            break;
        }
    }
    cout<<"Max profit = "<<s<<endl;

}
