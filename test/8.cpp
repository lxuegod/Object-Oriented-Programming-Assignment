#include<iostream>
using namespace std;
void mySwap(int* a, int* b);
int main()
{
    int a=16,b=48;
    cout<<"a= "<<a<<", b="<<b<<endl;
    mySwap(&a,&b);
    cout<<"After Being Swapped: "<<endl;
    cout<<"a= "<<a<<", b="<<b<<endl;
    system("pause");
}
void mySwap(int* a, int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

#include<iostream>
using namespace std;
void mySwap(int& a, int& b);
int main()
{
    int a = 16, b = 48;
    cout << "a= " << a << ", b=" << b << endl;
    mySwap(a, b);
    cout << "After Being Swapped: " << endl;
    cout << "a= " << a << ", b=" << b << endl;
    system("pause");
}
void mySwap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
