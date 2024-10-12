#include <iostream>

using namespace std;

int n,k;
int D[1001][1001];

int main() {

    cin>>n>>k;

    for(int i=0; i<=n; i++){
        D[i][1]=i;
        D[i][0]=1;
        D[i][i]=1;
    }
    for(int i=2; i<=n; i++){
        for(int j=1; j<i; j++){
            D[i][j]=D[i-1][j-1]+D[i-1][j];
            D[i][j]%=10007;
        }
    }
    cout<<D[n][k]<<'\n';
    return 0;
}