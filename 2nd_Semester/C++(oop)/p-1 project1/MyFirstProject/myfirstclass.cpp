#include <bits/stdc++.h>
#include "myfirstclass.h"
using namespace std;
MyFirstClass::MyFirstClass()
{
    cout<<"Inside the constructor"<<endl;
}
MyFirstClass::~MyFirstClass()
{
    cout<<"Inside the distructor"<<endl;
}
void MyFirstClass::display()
{
    cout<<"Inside the display"<<endl;
}
void MyFirstClass::display2()const
{
    cout<<"I am a constant function"<<endl;
}
