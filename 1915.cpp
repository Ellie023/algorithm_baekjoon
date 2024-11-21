#include <iostream>
#include <cmath>

using namespace std;

int n,m;
int D[1001][1001];

int main() {

    cin>>n>>m;

    long max=0;

    for(int i=0; i<n; i++){
        string mline;
        cin>>mline;
        for(int j=0; j<m; j++){
            D[i][j]=mline[j]-'0';
            if(D[i][j]==1&&j>0&&i>0){
                D[i][j]=min(D[i-1][j-1],min(D[i-1][j],D[i][j-1]))+D[i][j];
            }
            if(max<D[i][j]){
                max=D[i][j];
            }
        }
    }
    cout<<max*max;

    return 0;
}