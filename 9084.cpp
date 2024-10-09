#include <iostream>
#include <vector>
using namespace std;

int count(int n, int m, vector<int> &coins){

    vector<int> dp(m+1,0);

    dp[0]=1;

    for(int i=0; i<n; i++){
        for(int j=coins[i]; j<=m; j++){//1,2,5
            dp[j]=dp[j]+dp[j-coins[i]];//21 32 43 54 65 76 87
        }
    }
    return dp[m];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> coins(n);
        for(int i=0; i<n; i++){
            cin>>coins[i];
        }
        cin>>m;
        cout<<count(n,m,coins)<<'\n';
    }
    return 0;
}