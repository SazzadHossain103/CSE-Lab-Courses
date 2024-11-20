/*
types of polymorphism
1. compile time / static (or early) binding polymorphism = function overloading
2. run time / dynamic (or late) binding polymorphism = function overriding
*/


#include<bits/stdc++.h>
using namespace std;

class shape
{
public:
    double dim1,dim2;
    shape(double dim1,double dim2) // constractor
    {
        this -> dim1 = dim1;
        this -> dim2 = dim2;
    }
    virtual double area()
    {
        return 0;
    }

};
class triangle : public shape
{
public:
    triangle(double dim1,double dim2) // constructor
    : shape(dim1,dim2)
    {

    }
    double area()
    {
        return 0.5*dim1*dim2;
    }
};
class rectangle : public shape
{
public:
    rectangle(double dim1,double dim2)
    : shape(dim1,dim2)
    {

    }
    double area()
    {
        return dim1*dim2;
    }
};



int main()
{
    shape *p;
    triangle t(10,20);
    rectangle r(10,20);

    p=&t;
    cout<<"Triangle Area = "<<p -> area()<<endl;

    p=&r;
    cout<<"Rectangle Area = "<<p -> area()<<endl;
}
