#include<bits/stdc++.h>
using namespace std;


int main(){
    int n=4;
    int c = 5;
    int w[5]={0,3,2,5,4};
    int p[5]={0,4,3,6,5};
    int k[n+1][c+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=c; j++){
            if(i==0 || j==0) k[i][j]=0;
            else if(w[i]>j)k[i][j]=k[i-1][j];
            else k[i][j]=max(k[i-1][j] ,k[i-1][j-w[i]] + p[i]);
        }
    }
    cout<<k[n][c]<<endl;


}
