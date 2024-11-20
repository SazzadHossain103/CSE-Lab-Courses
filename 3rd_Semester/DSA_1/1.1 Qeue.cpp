#include<bits/stdc++.h>
using namespace std;

int q[100];
int font=0,bak=-1;

void enq(int n)
{
    q[++bak]=n;
}
void deq()
{
    if(font>bak){cout<<"Qeue is empty"<<endl;}
    int v=q[font];
    font++;
    cout<<v<<endl;
}

int main()
{
    enq(10);
    enq(20);
    enq(30);
    enq(40);

    deq();


}
