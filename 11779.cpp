#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>

using namespace std;
const int INF = numeric_limits<int>::max();
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> graph(n+1);

    for(int i=0; i<m; i++){
        int u,v,cost;
        cin>>u>>v>>cost;
        graph[u].emplace_back(cost,v);

    }
    int start, end;
    cin >> start >> end;

    vector<int> dist(n + 1, INF);
    vector<int> prev(n + 1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();

        if (cost > dist[u]) continue;

        for (auto &[next_cost, v] : graph[u]) {
            int total_cost = cost + next_cost;
            if (total_cost < dist[v]) {
                dist[v] = total_cost;
                prev[v] = u;
                pq.emplace(total_cost, v);
            }
        }
    }

    // 최소 비용 출력
    cout << dist[end] << '\n';

    // 경로 역추적
    stack<int> path;
    for (int v = end; v != -1; v = prev[v])
        path.push(v);

    cout << path.size() << '\n';
    while (!path.empty()) {
        cout << path.top() << ' ';
        path.pop();
    }

    cout << '\n';

    return 0;
}