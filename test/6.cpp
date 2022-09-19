#include <iostream>
#define M 100
using namespace std;
 
bool judgePrime(int n){
  if(n<2){
    return false;
  }
  for(int i=2;i*i<=n;i++){
    if(n%i==0) return false;
  }
  return true;
}

int main(){
  for(int i = 2; i <= M; i++) {
    if(judgePrime(i)) {
      cout<<"  "<<i;
    }
  }
    cout<<endl;
    return 0;
}