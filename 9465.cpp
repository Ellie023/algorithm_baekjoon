#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;

    while(T--){
        int n;
        cin>>n;

        vector<vector<int>> sticker(2,vector<int>(n));

        for(int i=0; i<n; i++) cin>>sticker[0][i];
        for(int i=0; i<n; i++) cin>>sticker[1][i];

        if(n==1){
            cout << max(sticker[0][0], sticker[1][0]) << '\n';
            continue;
        }

        vector<vector<int>> dp(2, vector<int>(n));

        dp[0][0] = sticker[0][0];  // 첫 번째 열 위쪽 스티커 선택
        dp[1][0] = sticker[1][0];  // 첫 번째 열 아래쪽 스티커 선택

        dp[0][1] = dp[1][0] + sticker[0][1];
        dp[1][1] = dp[0][0] + sticker[1][1];


        for (int i = 2; i < n; i++) {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + sticker[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + sticker[1][i];
        }

        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }
    return 0;
}