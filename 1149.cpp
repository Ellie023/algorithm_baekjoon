#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int R=0, G=1, B=2;

int paint(int n,vector<vector<int>>& houses){
    vector<vector<int>> dp(n+1,vector<int>(3,0));

    for(int i=1; i<=n; i++){
        dp[i][R]=min(dp[i-1][G],dp[i-1][B])+houses[i][R];
        dp[i][G]=min(dp[i-1][R],dp[i-1][B])+houses[i][G];
        dp[i][B]=min(dp[i-1][R],dp[i-1][G])+houses[i][B];
    }
    return min({ dp[n][R], dp[n][G], dp[n][B] });
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<vector<int>> houses(n+1,vector<int>(3,0));

    for(int i=1; i<=n; i++){
        cin>>houses[i][R]>>houses[i][G]>>houses[i][B];
    }
    cout<<paint(n,houses);
    return 0;
}