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

/// Selection sort
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(ar[j]<ar[i]){
                int t=ar[j];
                ar[j]=ar[i];
                ar[i]=t;
            }
        }
    }
//    sort(s.begin(),s.end());
    cout<<s<<endl;
