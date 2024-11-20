#include<bits/stdc++.h>
using namespace std;

void margearr(int a[], int  l, int m, int h, int n){
    int i = l;
    int j = m+1;
    int k = l;
    int t[n];
    while(i<=m && j<=h){
        if(a[i]<=a[j]){
            t[k]=a[i]; i++; k++;
        }
        else {
            t[k]=a[j]; j++; k++;
        }
    }
    while(i<=m){
        t[k]=a[i]; i++; k++;
    }
    while(j<=h){
        t[k]=a[j]; j++; k++;
    }
    for(int p=l; p<=h; p++){
        a[p]= t[p];
    }
}

void margesort(int a[], int l, int h, int n){

    int m = l + ( h-l )/2;
    if(l<h){
        margesort(a,l,m,n);
        margesort(a,m+1,l,n);
        margearr(a,l,m,h,n);
    }
}


int main() {

    int n; cin>>n;
    int a[n];
    for(int i=0; i<n; i++)cin>>a[i];
    margesort(a,0,n-1,n);

    cout << "After Sorting" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }



    return 0;
}
