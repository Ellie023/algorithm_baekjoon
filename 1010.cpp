#include <iostream>

using namespace std;

int main() {

    int t,n,m;
    int D[31][31];
    for(int i=0; i<=30; i++){
        D[i][i]=i;
        D[i][0]=1;
        D[i][i]=1;
    }
    for(int i=2; i<=30; i++){
        for(int j=1; j<i; j++){
            D[i][j]=D[i-1][j]+D[i-1][j-1];
        }
    }
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>n>>m;
        cout<<D[m][n]<<'\n';
    }
    return 0;
}