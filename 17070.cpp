#include <iostream>
using namespace std;

const int MAX = 16;
int N;
int map[MAX][MAX];
int dp[MAX][MAX][3]; // [행][열][방향]

// 방향 상수
enum { HORIZONTAL, DIAGONAL, VERTICAL };

void solve() {
    dp[0][1][HORIZONTAL] = 1;

    for (int i = 0; i < N; ++i) {
        for (int j = 2; j < N; ++j) {
            if (map[i][j] == 1) continue;

            // 가로
            dp[i][j][HORIZONTAL] = dp[i][j - 1][HORIZONTAL] + dp[i][j - 1][DIAGONAL];

            // 세로
            if (i > 0)
                dp[i][j][VERTICAL] = dp[i - 1][j][VERTICAL] + dp[i - 1][j][DIAGONAL];

            // 대각선 (3칸 다 비어야 함)
            if (i > 0 && map[i - 1][j] == 0 && map[i][j - 1] == 0)
                dp[i][j][DIAGONAL] = dp[i - 1][j - 1][HORIZONTAL] + dp[i - 1][j - 1][VERTICAL] + dp[i - 1][j - 1][DIAGONAL];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> map[i][j];

    solve();

    int result = dp[N - 1][N - 1][HORIZONTAL] +
                 dp[N - 1][N - 1][DIAGONAL] +
                 dp[N - 1][N - 1][VERTICAL];

    cout << result << '\n';
    return 0;
}
