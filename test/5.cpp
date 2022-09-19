#include <iostream>
using namespace std;
int main()
{
    int m,n;
    int j=0;
    for(int i = 0; i<= 1000; i++) {
        int a,b,c;
        a=i/100;  //百位
        b=(i/10)%10;  //十位
        c=i%10;  //个位
        if(i==a*a*a+b*b*b+c*c*c) {
            cout<<i<<" ";
            j++;
        }
    }
    cout<<endl;
    return 0;
}