#include <iostream>
using namespace std;
int main(){
    int a, b, tmp;
    cin>>a>>b;
    cout<<"交换前:a = "<<a<<" b = "<<b<<endl;
    tmp = a;
    a = b;
    b = tmp;
    cout<<"交换后:a = "<<a<<" b = "<<b<<endl;
    return 0;
}