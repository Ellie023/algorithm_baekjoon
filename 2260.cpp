#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> mapData;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct State {
    int x, y, dist, broken;
};

int bfs() {
    vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(2, false)));
    queue<State> q;
    q.push({0, 0, 1, 0});
    visited[0][0][0] = true;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        if (cur.x == N - 1 && cur.y == M - 1) {
            return cur.dist;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            // 벽이 아닌 경우
            if (mapData[nx][ny] == 0 && !visited[nx][ny][cur.broken]) {
                visited[nx][ny][cur.broken] = true;
                q.push({nx, ny, cur.dist + 1, cur.broken});
            }
                // 벽인데 아직 부순 적이 없을 때
            else if (mapData[nx][ny] == 1 && cur.broken == 0 && !visited[nx][ny][1]) {
                visited[nx][ny][1] = true;
                q.push({nx, ny, cur.dist + 1, 1});
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    mapData = vector<vector<int>>(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            mapData[i][j] = row[j] - '0';
        }
    }

    cout << bfs() << '\n';
    return 0;
}
