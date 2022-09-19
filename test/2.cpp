#include <iostream>
using namespace std;
int const n = 20;
long long Factorial(int m) {
    long long sum = 1;
    for(int i = 1; i <= m; i++) {
        sum *= i;
    }
    return sum;
}
int main() {
    long long sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += Factorial(i);
    }
    cout<<sum<<endl;
}