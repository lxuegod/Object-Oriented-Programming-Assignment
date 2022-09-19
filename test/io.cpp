#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    cout<<setiosflags(ios::right)<<setw(20)<<setfill('0')<<"左对齐"
    <<endl<<resetiosflags(ios::right)<<setw(20)<<"ni hao"<<endl;

    cout<<setiosflags(ios::scientific)<<setprecision(8)
    <<7.0/3<<endl<<resetiosflags(ios::scientific);

    cout<<setiosflags(ios::fixed)<<setprecision(6)<<10.0/3<<endl;
    return 0;
}