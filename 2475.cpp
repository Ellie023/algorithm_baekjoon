#include <iostream>
#include <cmath>
using namespace std;

int main() {

    long long sum=0;
    int a;
    for(int i=0; i<5; i++){
        cin>>a;
        a=pow(a,2.0);
        sum+=a;
    }
    sum%=10;
    cout<<sum;
    return 0;
}