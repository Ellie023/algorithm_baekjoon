#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
void dfs(int a, int b, int h, int w, vector<vector<int>> &grape) {
    grape[a][b] =2;//방문

    for(int i = 0; i < 8; i++) {
        int r = a + dx[i];
        int c = b + dy[i];

        if(r >= 0 && r < h && c >= 0 && c < w && grape[r][c] == 1) {//found
            dfs(r, c, h, w, grape);
        }
    }
}

int cal(int w, int h, vector<vector<int>>&grape){
    int cnt = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(grape[i][j] == 1) {//FOUND
                cnt++;
                dfs(i, j, h, w, grape);
            }
        }
    }
    return cnt;
}
int main() {
    vector<vector<int>> grape;
    int w,h;
    while(1) {
        cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }
        grape.assign(h, vector<int>(w, 0));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> grape[i][j];
            }
        }
        cout << cal(w, h, grape) << '\n';
    }
    return 0;
}