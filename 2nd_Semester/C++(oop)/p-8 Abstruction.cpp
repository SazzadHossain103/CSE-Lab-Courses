/*
what is abstraction?
= abstraction is the process of hiding the implementation details and showing only the
functionality to the user.

properties of abstract class:
1.object can not be created.
2.we can create pointer and reference of base abstract class points.
3.it can have constructor
*/
#include<bits/stdc++.h>
using namespace std;

class MoblieUser
{
public:
    virtual void sendmessage()=0; // pure virtual function
    void call()
    {
       cout<<"Hello"<<endl;
    }
};
class sazzad : public MoblieUser
{
public :
    void sendmessage()
    {
        cout<<"Hi, I am Sazzad"<<endl;
    }
};
class rohim : public MoblieUser
{
public :
    void sendmessage()
    {
        cout<<"Hi, I am Rohim"<<endl;
    }
};

int main()
{
    MoblieUser *p; // always make super/base class pointer
    sazzad s;
    rohim r;

    p->call();

    p=&s;
    p->sendmessage(); // pointer called

    p=&r;
    p->sendmessage();



}
