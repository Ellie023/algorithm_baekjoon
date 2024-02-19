#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>m>>n;
    vector<int> A(n+1);

    for(int i=2; i<=n; i++){
        A[i]=i;
    }
    for(int i=2; i<=sqrt(n); i++){
        if(A[i]==0){
            continue;
        }
        for(int j=i+i; j<=n; j=j+i){
            A[j]=0;
        }
    }
    for(int i=m; i<=n; i++){
        if(A[i]!=0){
            cout<<A[i]<<"\n";
        }
    }
    return 0;
}