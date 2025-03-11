#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
char map[26][26];
vector<int> ans;
bool visited[26][26];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void bfs(int row, int col){
    queue<pair<int,int>> q;
    q.push(make_pair(row,col));
    visited[row][col]=true;
    int cnt=0;
    cnt++;
    while(!q.empty()){
        int x_next =q.front().first;
        int y_next =q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int x=dx[i]+x_next;
            int y=dy[i]+y_next;
           if(x>=0&&y>=0&&x<n&&y<n&&visited[x][y]==false&&map[x][y]=='1') {
               q.push(make_pair(x, y));
               visited[x][y] = true;
               cnt++;
           }
        }
    }
    ans.push_back(cnt);
}

int main() {

    string a;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>map[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j]=='1'&&!visited[i][j]){
                bfs(i,j);
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<'\n';
    }

    return 0;
}