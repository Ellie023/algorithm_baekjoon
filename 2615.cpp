#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix;
const int SIZE = 20, EMPTY = 0;

//좌표 증가량 4개 동시에 검사
const vector<int> dx = {-1, 0, 1, 1};
const vector<int> dy = {1, 1, 1, 0};


//범위와 돌의 종류가 유효한가??
bool isValid(matrix &board, int x, int y, int color) {
    return (x > 0 && x < SIZE && y > 0 && y < SIZE && board[x][y] == color);
}

bool checkWin(matrix &board, int x, int y) {
    int color = board[x][y]; // 현재 색상

    for (int idx = 0; idx < 4; idx++) {
        int cnt = 1;    // 같은 색상, 같은 방향

        //4개 동시에 검사한다, 이전 돌들
        int prev_x = x - dx[idx], prev_y = y - dy[idx];
        int next_x = x + dx[idx], next_y = y + dy[idx];

            if (isValid(board, prev_x, prev_y, color)) {
            continue; // 같은 방향에서 그 이전에도 같은 색 돌이 있었다면 넘긴다.
        }

        //연속으로 같은 색상,종류 5개 모두 놓였나요?
        while (isValid(board, next_x, next_y, color) && cnt < 6) {
            //4개 동시에 검사한다, 다음 돌들
            next_x += dx[idx];
            next_y += dy[idx];
            cnt++;//같은 방향, 색상의 돌이므로 count
        }
        // cnt가 5일 때만 true 리턴
        if (cnt == 5) {
            return true;
        }
    }
    //5가 아닌 경우 모두 false 리턴
    return false;
}

int main() {
    // 입력
    matrix board(SIZE, vector<int>(SIZE, 0)); // 바둑판

    //입력
    for (int i = 1; i < SIZE; i++)
        for (int j = 1; j < SIZE; j++)
            cin >> board[i][j];

    // 연산
    for (int y = 1; y < SIZE; y++) {
        for (int x = 1; x < SIZE; x++) {
            // 없으면 넘긴다.
            if (board[x][y] == EMPTY) {
                continue;
            }

            //연속적으로 5알이 놓였다면 정답 출력
            if (checkWin(board, x, y)) {
                cout << board[x][y] << '\n'
                     << x << ' ' << y;
                return 0;
            }
        }
    }
    cout << 0;

}