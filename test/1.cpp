#include <iostream>
using namespace std;
int const n = 10;
int main() {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += i;
    }
    cout<<sum<<endl;
    return 0;
}