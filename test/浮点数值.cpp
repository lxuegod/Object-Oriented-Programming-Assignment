#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    float a = 34.92;
    cout<<setiosflags(ios::fixed)<<setprecision(4)<<a<<endl<<resetiosflags(ios::scientific);
    return 0;
}
//     void Clock::ShowTime()
// {
//     cout<<this->Hour<<":"<<this->Minute<<":"<<this->Second<<endl;
// }