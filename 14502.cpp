#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int lab[8][8];
int temp[8][8];
int dx[4] = {-1, 0, 1, 0}; // 상, 우, 하, 좌
int dy[4] = {0, 1, 0, -1};
int maxSafeArea = 0;

void copyMap(int src[8][8], int dest[8][8]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            dest[i][j] = src[i][j];
}

void spreadVirus() {
    int virusMap[8][8];
    copyMap(temp, virusMap);

    queue<pair<int, int>> q;

    // 초기 바이러스 위치 삽입
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (virusMap[i][j] == 2)
                q.push({i, j});

    // BFS로 바이러스 퍼뜨리기
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (virusMap[nx][ny] == 0) {
                    virusMap[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
    }

    // 안전 영역 계산
    int safe = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (virusMap[i][j] == 0)
                safe++;

    maxSafeArea = max(maxSafeArea, safe);
}

void makeWall(int count) {
    if (count == 3) {
        copyMap(lab, temp);
        spreadVirus();
        return;
    }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (lab[i][j] == 0) {
                lab[i][j] = 1;
                makeWall(count + 1);
                lab[i][j] = 0;
            }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> lab[i][j];

    makeWall(0);

    cout << maxSafeArea << endl;
    return 0;
}
