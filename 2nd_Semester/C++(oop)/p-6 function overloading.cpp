/*
function overloading
1. function name same
2. parameter difference
3. same(one)class
4. Inheritance is not involved
5. One method does not hide another
*/
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

void add(int x, int y)
{
    int sum = x + y;
    cout << "Sum : " << sum  << endl;
}


void add(int x, int y, int z)
{
    int sum = x + y + z;
    cout << "Sum : " << sum  << endl;
}

int main()
{

    add(10, 20);
    add(10, 20, 30);

    getch();
}
