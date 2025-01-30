#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef pair<int, int> Edge;

vector<int> dijkstra(int start, int V, vector<vector<Edge>>& graph) {
    vector<int> dist(V + 1, INT_MAX);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (cost > dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;

    vector<vector<Edge>> graph(V + 1);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int v1, v2;
    cin >> v1 >> v2;

    // 1. 다익스트라로 각 구간의 최단 거리 계산
    vector<int> dist_from_start = dijkstra(1, V, graph);
    vector<int> dist_from_v1 = dijkstra(v1, V, graph);
    vector<int> dist_from_v2 = dijkstra(v2, V, graph);

    // 2. 두 가지 경로를 계산
    long long path1 = (long long)dist_from_start[v1] + dist_from_v1[v2] + dist_from_v2[V];
    long long path2 = (long long)dist_from_start[v2] + dist_from_v2[v1] + dist_from_v1[V];

    // 3. 최단 경로 선택
    long long result = min(path1, path2);

    if (result >= INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << result << '\n';
    }

    return 0;
}
