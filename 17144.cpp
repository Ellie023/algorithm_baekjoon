#include <iostream>
#include <vector>
using namespace std;

int r, c, t;
int room[51][51];
int temp[51][51];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int up_row, down_row;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool found = false;
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> room[i][j];
            if (room[i][j] == -1) {
                if (!found) {
                    up_row = i;
                    found = true;
                } else {
                    down_row = i;
                }
            }
        }
    }
}

void spreadDust() {
    // 초기화
    for (int i = 0; i < r; i++)
        fill(temp[i], temp[i] + c, 0);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (room[i][j] <= 0) continue;

            int spreadAmount = room[i][j] / 5;
            int spreadCount = 0;

            for (int d = 0; d < 4; d++) {
                int ni = i + dr[d];
                int nj = j + dc[d];

                if (ni < 0 || ni >= r || nj < 0 || nj >= c || room[ni][nj] == -1) continue;

                temp[ni][nj] += spreadAmount;
                spreadCount++;
            }

            temp[i][j] -= spreadAmount * spreadCount;
        }
    }

    // 확산 결과 적용
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            room[i][j] += temp[i][j];
}

void cleanAir() {
    // 위쪽 반시계 순환
    for (int i = up_row - 1; i > 0; i--) room[i][0] = room[i - 1][0];
    for (int i = 0; i < c - 1; i++) room[0][i] = room[0][i + 1];
    for (int i = 0; i < up_row; i++) room[i][c - 1] = room[i + 1][c - 1];
    for (int i = c - 1; i > 1; i--) room[up_row][i] = room[up_row][i - 1];
    room[up_row][1] = 0;

    // 아래쪽 시계 방향 순환
    for (int i = down_row + 1; i < r - 1; i++) room[i][0] = room[i + 1][0];
    for (int i = 0; i < c - 1; i++) room[r - 1][i] = room[r - 1][i + 1];
    for (int i = r - 1; i > down_row; i--) room[i][c - 1] = room[i - 1][c - 1];
    for (int i = c - 1; i > 1; i--) room[down_row][i] = room[down_row][i - 1];
    room[down_row][1] = 0;
}

int calculateDust() {
    int total = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (room[i][j] > 0)
                total += room[i][j];
    return total;
}

void solve() {
    while (t--) {
        spreadDust();
        cleanAir();
    }
    cout << calculateDust() << '\n';
}

int main() {
    input();
    solve();
    return 0;
}
