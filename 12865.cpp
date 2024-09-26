#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n,k;

    cin>>n>>k;

    vector<pair<int,int>> items(1,{0,0});

    int w,v;

    for(int i=1; i<=n; i++){
        cin>>w>>v;
        items.push_back({w,v});
    }
    sort(items.begin(),items.end());

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));


    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j - items[i].first >= 0) {
                dp[i][j] = max(dp[i - 1][j - items[i].first] + items[i].second, dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][k] << "\n";
    return 0;
}