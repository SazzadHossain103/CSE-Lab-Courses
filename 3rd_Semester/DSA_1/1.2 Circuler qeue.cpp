#include<bits/stdc++.h>
using namespace std;
int N=5;
int q[5];
int font=-1;
int bak=-1;
void enq(int n)
{
    if((bak+1)%N==font){
        cout<<"full"<<endl;
    }
    else if(font==-1 && bak==-1){
        font=bak=0;
        q[bak]=n;
    }
    else{
        bak=(bak+1)%N;
        q[bak]=n;
    }
}
void deq()
{
    if(font==-1 && bak==-1){
        cout<<"empty"<<endl;
    }
    else if(font==bak){
        cout<<q[font]<<endl;
        font=bak=-1;
    }
    else{
        cout<<q[font]<<endl;
        font=(font+1)%N;
    }
}
void display(){
    int i=font;
    if(font==-1 && bak==-1){
        cout<<"empty"<<endl;
    }
    else{
        while(i!=bak){
            cout<<q[i]<<endl;
            i=(i+1)%N;
        }
        cout<<q[bak]<<endl;
    }
}

int main()
{

    enq(10);
    enq(20);
    enq(30);
    enq(40);
    deq();
    deq();
    enq(50);
    enq(60);
    enq(70);
    enq(80);
    deq();
//    display();


return 0;
}
