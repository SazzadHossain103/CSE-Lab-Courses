#include<bits/stdc++.h>
using namespace std;

int s[100];
int top=-1;

void push(int n)
{
    top++;
    s[top]=n;
    //s[top++]=n;
}

void pop()
{
    if(top==-1) {cout<<"stack is empty"<<endl; }
    int t=s[top];
    top--;
    cout<<t<<endl;
    //return s[top--];
}

int main()
{
    push(10);
    push(15);
    push(12);
    pop();
    push(16);
    pop();
    pop();
    pop();

}

