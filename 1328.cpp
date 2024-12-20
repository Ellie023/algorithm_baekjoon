#include <iostream>

using namespace std;

int n,L,R;
long mod=1000000007;
long D[101][101][101];

int main() {

    cin>>n>>L>>R;
    D[1][1][1]=1;

    for(int i=2;  i<=n; i++){
        for(int j=1; j<=L; j++){
            for(int k=1; k<=R; k++){
                D[i][j][k]=(D[i-1][j][k]*(i-2)+(D[i-1][j][k-1]+D[i-1][j-1][k]))%mod;
            }
        }
    }
    cout<<D[n][L][R];
    return 0;
}