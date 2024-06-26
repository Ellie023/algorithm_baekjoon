#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<vector<int>>board;

int ans;

void dfs(int x, int y, int depth, int sum) {

    //4방향을 한꺼번에 연산하기 위해서 정의
    vector<int> dx = { -1,0,1,0 };
    vector<int> dy = { 0,1,0,-1 };

    if (depth == 4) { // ans 최대값 갱신
        ans = max(ans, sum);//ans,sum 중 최대값
        return;
    }



    for (int i = 0; i < 4; i++) {
        // 유효한 칸 선택
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 범위를 벗어났거나 이미 방문한 블록이라면 넘어가기
        if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || !board[nx][ny]) {
            continue;
        }

        int temp = board[nx][ny]; // 방문 처리하기 전 해당 칸 가치 저장
        board[nx][ny] = 0; // 방문처리

        if (depth == 2) { // ㅜ 모양은 열외이므로 현재 위치에서 다시 탐색해준다.
            dfs(x, y, depth + 1, sum + temp);
        }
        dfs(nx, ny, depth + 1, sum + temp); // 선택한 칸으로 이동

        board[nx][ny] = temp; // 이후의 케이스에서 재방문할 수 있으므로 원래대로 돌려줌

       // 선택한 칸의 가치를 더해주고 다음 탐색으로
    }
}



int main() {

    // 입력
    int n, m;
    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];//종이에 쓰여 있는 수
        }
    }

    // 연산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp = board[i][j];
            board[i][j] = 0;
            dfs(i, j, 1, temp);//dfs 함수 이용
            board[i][j] = temp;
        }
    }

    // 출력
    cout << ans;
    return 0;
}