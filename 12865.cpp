#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n,k;
    cin>>n>>k;

    vector<pair<int,int>> items(1,{0,0});

    int w,v;
    for(int i=0; i<n; i++){
        cin>>w>>v;
        items.push_back({w,v});
    }
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(j>=items[i].first){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-items[i].first]+items[i].second);
                }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][k];

    return 0;
}