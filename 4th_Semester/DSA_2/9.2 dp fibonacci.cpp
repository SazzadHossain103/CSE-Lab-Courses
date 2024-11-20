/// dynamic program (dp) fibonacci

#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[100];

long long fibo(int n){
    if(dp[n]!=-1)return dp[n];
    else dp[n]= fibo(n-1)+ fibo(n-2);
    return dp[n];
}

int main(){

    for(int i=0; i<100; i++){
        dp[i]= -1;
    }
    dp[0]=0;
    dp[1]=1;
    cout<<fibo(55);
}
