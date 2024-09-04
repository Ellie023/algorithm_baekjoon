#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4]={-1,0,0,1};
int dy[4]={0,1,-1,0};
int n,m;
vector<vector<int>> map;
vector<vector<bool>> visited;
vector<vector<int>> result;

void bfs(int y, int x){
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x]=true;
    result[y][x]=0;

    while(!q.empty()){
        pair<int,int> cur_pair=q.front();

        for(int i=0; i<4; i++){
           int x_next=dx[i]+cur_pair.second;
           int y_next=dy[i]+cur_pair.first;

           if(x_next<0||x_next>=m||y_next<0||y_next>=n){
               continue;
           }
           if(map[y_next][x_next]==1&&!visited[y_next][x_next]){
               q.push({y_next,x_next});
               visited[y_next][x_next]=true;
               result[y_next][x_next]=result[cur_pair.first][cur_pair.second]+1;
           }
        }
        q.pop();
    }
}

int main() {

    int x,y;
    cin>>n>>m;
    map.resize(n,vector<int> (m,0));
    visited.resize(n,vector<bool> (m,false));
    result.resize(n,vector<int> (m,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];

            if(map[i][j]==2){
                x=j;
                y=i;
            }

        }
    }
    bfs(y,x);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(result[i][j]==0&&map[i][j]==1){
                cout<<-1<<' ';
            }
            else{
                cout<<result[i][j]<<' ';
            }
        }
        cout<<'\n';
    }
    return 0;
}