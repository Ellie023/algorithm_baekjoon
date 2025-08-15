#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<long long> cost(N + 1);
        for (int i = 1; i <= N; ++i) cin >> cost[i];

        vector<vector<int>> g(N + 1);
        vector<int> indeg(N + 1, 0);
        for (int i = 0, a, b; i < K; ++i) {
            cin >> a >> b;          // a가 b의 선행작업
            g[a].push_back(b);
            ++indeg[b];
        }
        int W; cin >> W;

        queue<int> q;
        vector<long long> dp(N + 1, 0);

        for (int i = 1; i <= N; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
                dp[i] = cost[i];    // 선행이 없으면 자기 시간
            }
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                dp[v] = max(dp[v], dp[u] + cost[v]); // u를 통해 v 완성시간 후보
                if (--indeg[v] == 0) q.push(v);
            }
        }

        cout << dp[W] << "\n";
    }
    return 0;
}
