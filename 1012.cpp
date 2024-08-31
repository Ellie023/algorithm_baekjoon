#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector<vector<int>> field;
vector<vector<int>> visited;
int dx[] = { -1, 1, 0, 0 }; // 좌, 우, 상, 하
int dy[] = { 0, 0, -1, 1 };

int t,m,n,k;
void bfs(int y,int x){
    queue<pair<int,int>> q;

    q.push(make_pair(x,y));
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (field[ny][nx] == 0||visited[ny][nx]==1) continue;
            if (field[ny][nx] == 1) {
                field[ny][nx] = 0;
                q.push(make_pair(nx, ny));
                visited[ny][nx]=1;
            }
        }
    }
}


int main() {




    cin>>t;
    for(int i=0; i<t; i++) {

        cin>>m>>n>>k;
        field.assign(n, vector<int>(m,0));
        visited.assign(n, vector<int>(m,0));

       for(int i=0; i<k; i++){
            int x,y;
            cin>>x>>y;
            field[y][x]=1;
       }

       int result=0;

       for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
               if(field[i][j]==0) continue;
                else{
                    bfs (i,j);
                    result++;
                }
           }

       }

       cout<<result<<'\n';
        field.clear();
        visited.clear();
        field.shrink_to_fit();
        visited.shrink_to_fit();

    }
    return 0;
}