/*
what is constructor?
= Constructor is a special type of function that is used to initialize the object.

what are the properties of constructor?
= 1. Constructor is a special type of function.
  2. Constructor has the same name as that of the class it belongs.
  3. It has no return type ... not even void.
  4. It is called automatically.
*/
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

class Student
{
    public:
        //variables
        int id;
        double gpa;

        //functions
        void display()
        {
            cout << id << "  " << gpa << endl;
        }
        // default constructor
        Student()
        {
            cout << "This is a default constructor" << endl;
        }
        // parametrized constructor
        Student(int x, double y)
        {
           id = x;
           gpa = y;
        }
/*        // distructor
        ~Student()
        {
            cout << "This is a distructor" << endl;
        }
 */

};
class student2
{
    public:

       // constant variable
        const int admissionFee,examFee;
        student2(int a, int b)
        : admissionFee(a),examFee(b)//constant initializer
        {
            cout<<admissionFee<<"  "<<examFee<<endl;
        }
};

int main()
{
    Student ob; //default  constructor call


    Student s1(101,3.92);// call parametrized constructor
    s1.display();

    Student s2(102,3.44);
    s2.display();

    student2 s3(500,300);// constant initializer call


    getch();
}


