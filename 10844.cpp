#include <iostream>

using namespace std;

int n;
long D[101][11];
long mod=1000000000;
int main() {

    cin>>n;
    for(int i=1; i<=9; i++){
        D[1][i]=1;
    }
    for(int i=2; i<=n; i++){
        D[i][0]=D[i-1][1];
        D[i][9]=D[i-1][8];

        for(int j=1; j<=8; j++){
            D[i][j]=(D[i-1][j-1]+D[i-1][j+1])%mod;
        }
    }
    long sum=0;

    for(int i=0; i<10; i++){
        sum=(sum+D[n][i])%mod;
    }
    cout<<sum;
    return 0;
}