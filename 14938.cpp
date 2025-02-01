#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

const int INF = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;

    vector<int> items(n + 1); // 각 지역의 아이템 수
    for (int i = 1; i <= n; i++) {
        cin >> items[i];
    }

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    // 자기 자신으로의 거리는 0으로 초기화
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    // 길 정보 입력
    for (int i = 0; i < r; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        dist[a][b] = l;
        dist[b][a] = l;
    }

    // 플로이드-워셜 알고리즘
    for (int k = 1; k <= n; k++) {         // 경유 노드
        for (int i = 1; i <= n; i++) {     // 출발 노드
            for (int j = 1; j <= n; j++) { // 도착 노드
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int max_items = 0;

    // 각 지역을 시작점으로 수색
    for (int i = 1; i <= n; i++) {
        int total_items = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] <= m) { // 수색 범위 내라면
                total_items += items[j];
            }
        }
        max_items = max(max_items, total_items);
    }

    cout << max_items << '\n';

    return 0;
}
