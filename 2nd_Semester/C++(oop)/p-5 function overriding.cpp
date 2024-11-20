/* function overriding
1. function name same
2. parameter same
3. class different ( it occurs between two classes subclass and a superclass
4. Return type must be same
5. Inheritance is involved
6. Child method hides parent another
*/
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

class Person
{
    public:
        void display()
        {
            cout << "I am a person" << endl;
        }
};
class Student : public Person
{
    public:
        void display()
        {
            cout << "I am a Student" << endl;
        }
};
class Teacher : public Person
{
    public:
        void display()
        {
            cout << "I am a Teacher" << endl;
        }
};

int main()
{
    Person p;
    p.display();

    Student s;
    s.display();

    Teacher t;
    t.display();

    getch();
}
