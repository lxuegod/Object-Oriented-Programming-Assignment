#include <iostream>
using namespace std;
class Computer
{
public:
    float add(int a, int b);
};

float Computer::add(int a, int b)
{
    return a+b;
}


class A : public Computer
{

};
int main() {

    return 0;
}