#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int N;
vector<vector<int>> space;

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};

struct Shark{
    int x,y;
    int size=2;
    int eaten=0;
    int time=0;
};
bool isInBounds(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}
int bfs(Shark &shark){
    while(1){
        vector<vector<int>> dist(N,vector<int>(N,-1));
        queue<pair<int,int>> q;
        q.push({shark.x,shark.y});
        dist[shark.x][shark.y]=0;

        vector<tuple<int,int,int>> fishList;

        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for(int dir=0; dir<4; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (!isInBounds(nx, ny)) continue;
                if (dist[nx][ny] != -1) continue;
                if (space[nx][ny] > shark.size) continue;

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});

                if (space[nx][ny] != 0 && space[nx][ny] < shark.size) {
                    fishList.push_back({dist[nx][ny], nx, ny});
                }
            }
        }

        if (fishList.empty()) break;

        sort(fishList.begin(), fishList.end()); // 거리, x, y 순으로 정렬
        int d, fx, fy;
        tie(d, fx, fy) = fishList[0];


        shark.x = fx;
        shark.y = fy;
        shark.time += d;
        shark.eaten++;
        if (shark.eaten == shark.size) {
            shark.size++;
            shark.eaten = 0;
        }

        space[fx][fy] = 0; // 먹은 위치는 빈 칸 처리
    }

    return shark.time;
    }

int main() {

    cin>>N;
    space=vector<vector<int>>(N,vector<int>(N));
    Shark shark;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>space[i][j];
            if(space[i][j]==9){
              shark.x=i;
              shark.y=j;
              space[i][j]=0;
            }
        }
    }

    cout<<bfs(shark)<<'\n';
    return 0;
}