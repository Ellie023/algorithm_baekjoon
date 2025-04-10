#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

const int INF=1e9;bool bellmanFord(int n, const vector<tuple<int, int, int>>& edges) {
    vector<int> dist(n + 1, 0); // 가상 노드 0부터 시작하므로 모두 0으로 초기화

    // n번 반복
    for (int i = 0; i < n; i++) {
        for (const auto &[u, v, w]: edges) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (i == n - 1) return true; // 마지막 반복에서 갱신되면 음수 사이클 있음
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin>>TC;

    while(TC--){
        int N,M,W;
        cin>>N>>M>>W;

        vector<tuple< int,int,int>> edges;

        for(int i=0; i<M; i++){
            int S,E,T;
            cin>>S>>E>>T;
            edges.push_back({S, E, T});
            edges.push_back({E, S, T});
        }

        for(int i=0; i<W; i++){
            int S, E, T;
            cin >> S >> E >> T;
            edges.push_back({S, E, -T});
        }

        if (bellmanFord(N, edges)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}