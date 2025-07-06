#include <bits/stdc++.h>
using namespace std;

static int cur[51][51], nxt[51][51];
static bool isCleaner[51][51];
int r, c, t;
int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};
int up_row, down_row;

inline bool in(int i, int j) {
    return i >= 0 && i < r && j >= 0 && j < c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력 및 공기청정기 마킹
    cin >> r >> c >> t;
    bool found = false;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> cur[i][j];
            if (cur[i][j] == -1) {
                isCleaner[i][j] = true;
                if (!found) { up_row = i; found = true; }
                else         down_row = i;
            }
        }
    }

    while (t--) {
        // 1) 먼지 확산
        // nxt 전 영역 0으로 초기화, 청정기는 -1로 복원
        for (int i = 0; i < r; i++) {
            memset(nxt[i], 0, c * sizeof(int));
        }
        nxt[up_row][0] = nxt[down_row][0] = -1;

        // 확산 계산: cur -> nxt
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int dust = cur[i][j];
                if (dust <= 0) {
                    if (dust < 0) nxt[i][j] = -1;  // 공기청정기
                    continue;
                }
                int spread = dust / 5, cnt = 0;
                for (int d = 0; d < 4; d++) {
                    int ni = i + dr[d], nj = j + dc[d];
                    if (in(ni, nj) && !isCleaner[ni][nj]) {
                        nxt[ni][nj] += spread;
                        cnt++;
                    }
                }
                // 남은 먼지
                nxt[i][j] += dust - spread * cnt;
            }
        }

        // 2) 공기청정기 작동 (순환)
        // 위쪽 반시계
        for (int i = up_row - 1; i > 0; i--)               nxt[i][0] = nxt[i - 1][0];
        for (int j = 0; j < c - 1; j++)                    nxt[0][j] = nxt[0][j + 1];
        for (int i = 0; i < up_row; i++)                   nxt[i][c - 1] = nxt[i + 1][c - 1];
        for (int j = c - 1; j > 1; j--)                    nxt[up_row][j] = nxt[up_row][j - 1];
        nxt[up_row][1] = 0;

        // 아래쪽 시계
        for (int i = down_row + 1; i < r - 1; i++)         nxt[i][0] = nxt[i + 1][0];
        for (int j = 0; j < c - 1; j++)                    nxt[r - 1][j] = nxt[r - 1][j + 1];
        for (int i = r - 1; i > down_row; i--)             nxt[i][c - 1] = nxt[i - 1][c - 1];
        for (int j = c - 1; j > 1; j--)                    nxt[down_row][j] = nxt[down_row][j - 1];
        nxt[down_row][1] = 0;

        // 3) 포인터 스왑 (cur ← nxt)
        for (int i = 0; i < r; i++)
            memcpy(cur[i], nxt[i], c * sizeof(int));
    }

    // 최종 먼지 합산
    long long answer = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (cur[i][j] > 0) answer += cur[i][j];
        }
    }
    cout << answer << "\n";
    return 0;
}
