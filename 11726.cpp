#include <iostream>

using namespace std;
int n;
long D[1001];
long mod=10007;
int main() {

    cin>>n;
    D[1]=1;
    D[2]=2;

    for(int i=3; i<=n; i++){
        D[i]=(D[i-1]+D[i-2])%mod;
    }
    cout<<D[n];

    return 0;
}