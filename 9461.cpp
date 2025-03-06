#include <iostream>
#include <vector>

using namespace std;

void solve(){

    unsigned long long P[110];

    P[1]=P[2]=P[3]=1;
    P[4]=P[5]=2;
    int n;

        cin>>n;
        for(int i=6; i<=n; i++){
            P[i]=P[i-2]+P[i-3];
        }
        cout<<P[n]<<'\n';
}

int main() {

    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0; i<t; i++) {
        solve();
    }
    return 0;
}