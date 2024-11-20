#include<bits/stdc++.h>
#define ll long long
using namespace std;

///coin change pblm ( 4 tk vanti coin use kore koto upay deya jay)
//cois = {1,2,3}
//change = 4;
//
//0 = {}
//1 ={1}
//2 ={1,1}{2}
//3 ={1,1,1}{1,2}{3}
//4 = {1,1,1,1}{1,1,2}{2,2}{1,3}  ans=4

int main(){

    int coins[3]={1,2,3};
    int change = 4;
    int dp[change+1] ={0};
    dp[0]=1;

    for(int i=0; i<3;  i++){
        for(int j=coins[i]; j<=change; j++){
            dp[j]+=dp[j-coins[i]];
        }
    }
    cout<<dp[change]<<endl;

}
