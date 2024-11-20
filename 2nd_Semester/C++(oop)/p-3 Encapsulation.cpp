/*
what is encapsulation?
= Encapsulation is a process of
1. combining variable and function in a single unit (class)
2. protecting data by declaring them as private

what is data hiding?
= Private data will be hidden from other classes and they can only be accessed through
public function of their current class. That is known as data hiding.
*/

#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

class student
{
private:
    string name;
public:
    void setName(string x)
    {
        name = x;
    }
    string getName()
    {
        return name;
    }
/*
    // this keyword
    string name2;
    student(string name2)
    {
        this -> name2 = name2;
    }
    void display()
    {
        cout << name2 << endl;
    }
*/
};

int main()
{
    student s1;
    s1.setName("Sazzad");
    cout<<s1.getName()<<endl;
/*
    student s2("Hossain");
    s2.display();
*/
}

