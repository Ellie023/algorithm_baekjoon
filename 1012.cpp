#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> field;
vector<vector<int>> visited;
int dx[] = { -1, 1, 0, 0 }; // 좌, 우, 상, 하
int dy[] = { 0, 0, -1, 1 };


int bfs(int x,int y){
    queue<pair<int,int>> q;

    q.push(make_pair(x,y));
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
            if (field[nx][ny] == 0) continue;
            if (field[nx][ny] == 1) {
                field[nx][ny] = 0;
                q.push(make_pair(nx, ny));
            }
        }
    }
}


int main() {


    int t,m,n,k,x;

    cin>>t;
    for(int i=0; i<t; i++) {

        cin>>m>>n>>k;
        field.resize(m, vector<int>(n));
        visited.resize(m, vector<int>(n));
       for(int i=0; i<k; i++){
            int x,y;
            cin>>x>>y;
            field[x][y]=1;
       }

       field.clear();
       visited.clear();

       int result=0;

       for(int i=0; i<m; i++){
           for(int j=0; j<n; j++){
               if(field[i][j]==0) continue;
                else{
                    bfs(i,j);
                    result++;
                }
           }

       }

       cout<<result;
    }
    return 0;
}