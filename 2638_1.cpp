#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N,M;
int board[100][100];
bool visited[100][100];

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

void markOutsideAir(){
    queue<pair<int,int>> q;
    q.push({0,0});
    fill(&visited[0][0],&visited[0][0]+100*100,false);
    visited[0][0]=true;

    while(!q.empty()){
        auto [x,y] =q.front();
        q.pop();
        for(int dir=0; dir<4; dir++){
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if(nx<0||ny<0||nx>=N||ny>=M) continue;
            if(!visited[nx][ny]&&board[nx][ny]==0){
                visited[nx][ny]=true;
                q.push({nx,ny});
            }
        }
    }
}
bool meltCheese() {
    vector<pair<int, int>> toMelt;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 1) {
                int cnt = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int ni = i + dx[dir];
                    int nj = j + dy[dir];
                    if (ni < 0 || nj < 0 || ni >= N || nj >= M) continue;
                    if (visited[ni][nj]) cnt++;
                }
                if (cnt >= 2) {
                    toMelt.push_back({i, j});
                }
            }
        }
    }

    for (auto [x, y] : toMelt) {
        board[x][y] = 0;
    }

    return !toMelt.empty();
}
int main() {

    cin>>N>>M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>board[i][j];
        }
    }
    int time =0;

    while(1){
        markOutsideAir();
        if (!meltCheese()) break;
        time++;
    }
    cout<<time<<'\n';

    return 0;
}