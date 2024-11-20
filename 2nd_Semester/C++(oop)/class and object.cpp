/*
what is class?
= Class is a template from which individual object can be created.

what is object?
= Any class tpye variable is called an object.
*/



#include<bits/stdc++.h>
using namespace std;

class student
{
public:
    int id;
    double cgpa;

    void value()
    {
        int x; // instane
        double y;
        cin>>x>>y;
        id=x;
        cgpa=y;
    }
    void display()
    {
        cout<<id<<"  "<<fixed<<setprecision(2)<<cgpa<<endl;
    }
/*   void setValue(int x, double y)//parameter function
    {
        id=x;
        cgpa=y;
    }*/

 /*  student(int x, double y)//parameter constructor

    {
        id=x;
        cgpa=y;
    }*/

    student()
    {
        cout<<"default constructor call"<<endl;
    }
};



int main()
{
/*  student sazzad; // object
    student bonhi(103,4.00); //constructor call

    sazzad.id=103;
    sazzad.cgpa=3.53;

    sazzad.setValue(103,3.53);

    sazzad.display;
 */
    student ob; //default  constructor call

    student sohan,sazzad;

    sohan.value();
    sohan.display();
    sazzad.value();
    sazzad.display();

}
