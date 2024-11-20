#include<bits/stdc++.h>
using namespace std;
int main()
{

///binary search

    int arr[] = { 10, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int n = sizeof(arr)/ sizeof(arr[0]);
    sort(arr,arr+n);

    int t=2;
    int mid;
    int st=0,en=n,f=0,idx;
    while(st<=en)
    {
        mid=st+(en-st)/2;
        if(arr[mid]==t){f=1; idx=mid;}
        if(arr[mid]<t)st=mid+1;
        else en=mid-1;
    }
    if(f==1)cout<<"found  "<<"index = "<<idx<<endl;
    else cout<<"not found"<<endl;

///liner search
    int arr[] = { 10, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int n = sizeof(arr)/ sizeof(arr[0]);
    int k = 3;
    int f=0, idx;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==k){
            f=1;
            idx=i;
            break;
        }
    }
    if(f==1){
        cout<<"found "<<"index = "<<idx<<endl;
    }
    else cout<<"not found"<<endl;

}
