#include <iostream>

using namespace std;
int factorial(int t){
    if(t==1){
        return 1;
    }
    int sum=1;
    for(int i=t; i>0; i--){
        sum*=i;
    }
    return sum;
}
int main() {

    int n,k;
    cin>>n>>k;
    int sum= factorial(n);
    sum/=(factorial(k)*factorial(n-k));

    cout<<sum;
    return 0;
}