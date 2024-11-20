#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ar[20],n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
    }

///delete array;
    int x;cin>>x;
    for(int i=x+1; i<n; i++)
    {
        ar[i-1]=ar[i];

    }
    for(int i=0; i<n-1; i++)
    {
        cout<<ar[i]<<" ";
    }

///array insert
    int x,y;cin>>x>>y;
    for(int i=n-1; i>=x; i--)
    {
        ar[i+1]=ar[i];
    }
    ar[x]=y;
    for(int i=0; i<n+1; i++)
    {
        cout<<ar[i]<<" ";
    }

}

///binary search

    int arr[] = { 10, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int n = sizeof(arr)/ sizeof(arr[0]);
    sort(arr,arr+n);

    int t=110;
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

///liner sort
    int arr[] = { 10, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int n = sizeof(arr)/ sizeof(arr[0]);
    int k;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]>arr[j])
            {
                k=arr[i];
                arr[i]=arr[j];
                arr[j]=k;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

///Babble sort
    string s="UITS";
    for(int i=0; i<s.size(); i++){
        for(int j=0; j<s.size()-i-1; j++){
            if(s[j]>s[j+1]){
                char temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
//    srt(s);
    cout<<s<<endl;
