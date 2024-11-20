/*
What is inheritance?
= The process of obtaining the data members and functions
  from one class to another class is known as inheritance.

What are the importance of inheritance?
= code re-usability
  application development time is less
  application take less memory
  application execution time is less

There are 5 types of inheritance
1. Single  = In this sort of inheritance, one subclass inherit from one superclass.
2. Multilevel  =  one superclass for one is the subclass for another.
3. Hierarchical  = Multiple subclass derived form single superclass.
4. Multiple = a class can inherit more than one class. A single child class can have multiple parent classes
5. Hybrid = is a combination of more than one type of inheritance
*/
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

class person
{
    public:
        string name;
        int age;

        void display1()
        {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }
};
class Student : public person // inheritance
{
    // name, age, display1()
    public:
        int id;

        void display2()
        {
            cout << "ID: " << id << endl;
            display1();
        }
};

int main()
{
    Student s1;
    s1.id = 103;
    s1.name = "Sazzad Hossain";
    s1.age = 20;
    s1.display2();

    getch();
}
