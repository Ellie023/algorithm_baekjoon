  #include <iostream>

using namespace std;
const int SIZE = 15;
  int n, ans;
  bool is_queen_in_col[SIZE];
  bool is_queen_in_left[SIZE * 2];
  bool is_queen_in_right[SIZE * 2];

void backtrack(int r) {
    if (r == n) {
        ans++;
        return;
    }
    for (int c = 0; c < n; c++) {
        // 세로, 좌하향 대각선, 우하향 대각선 모두에 퀸이 없을 경우 -> 퀸 배치
        if (!is_queen_in_col[c] && !is_queen_in_left[r + c] && !is_queen_in_right[r - c + n]) {
            // (r, c)에 퀸 배치
            is_queen_in_col[c] = true;              // c열 선택 체크
            is_queen_in_left[r + c] = true;         // 좌하향 대각선 선택 체크
            is_queen_in_right[r - c + n] = true;    // 우하향 대각선 선택 체크

            // 다음 행에도 놓기
            backtrack(r + 1);

            // 재탐색이 가능하도록 놓았던 퀸 회수
            is_queen_in_col[c] = false;
            is_queen_in_left[r + c] = false;
            is_queen_in_right[r - c + n] = false;
        }
    }
}
int main() {

    cin>>n;

    backtrack(0);

    cout<<ans;
    return 0;
}