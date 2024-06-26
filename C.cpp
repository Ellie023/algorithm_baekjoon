#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int, int>> q;

// 우,하,좌,상
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int w = 1000001, h = 1000001, result = 0;
int** graph;

bool IsInside(int ny, int nx) {
    return (0 <= nx && 0 <= ny && nx < w && ny < h);
}

void bfs() {
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (IsInside(ny, nx) && graph[ny][nx] == 0) {
                graph[ny][nx] = graph[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k, t;
    cin >> w >> h >> k >> t;

    // Dynamically allocate memory for graph
    graph = new int*[h];
    for (int i = 0; i < h; i++) {
        graph[i] = new int[w];
        fill(graph[i], graph[i] + w, 0); // Initialize graph with 0s
    }

    while (k--) {
        int a, b;
        cin >> a >> b;
        graph[a][b]++;
        q.push({a, b});
    }
    while (t--) {
        bfs();
    }

    long long sum = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (graph[i][j] ) {
                sum+=graph[i][j];
            }
        }
    }
    cout << sum;

    // Deallocate dynamically allocated memory
    for (int i = 0; i < h; ++i) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}
