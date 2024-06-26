#include <iostream>
#include <vector>
#include <queue>

using namespace std;



int bfs(int n, int m,int h, int raw, queue<pair<pair<int,int>, int>> &q, vector<vector<vector<int>>> &box){
    int w;
    int dr[6] = {-1, 1, 0, 0,0,0};
    int dc[6] = {0, 0, -1, 1,0,0};
    int dz[6]={0,0,0,0,1,-1};

    while(!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int e= q.front().second;
        w = box[r][c][e];
        q.pop();

        for(int i = 0; i < 6; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            int nz=e+dz[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m&&nz>=0 &&nz<h &&box[nr][nc][nz] == 0) {
                q.push(make_pair(make_pair(nr,nc),nz));
                box[nr][nc][nz] = w + 1;
                raw--;
            }
        }
    }

    if(raw == 0) {
        return w-1;
    }
    return -1;
}

int main() {

    int n,m,h,raw=0;

    cin>>m>>n>>h;
    vector<vector<vector<int>>> box(n,vector<vector<int>>(m,vector<int>(h,0)));
    queue<pair<pair<int,int>, int>> q;
    for(int z=0; z<h; z++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> box[i][j][z];
                if (box[i][j][z] == 1) {
                    q.push(make_pair(make_pair(i,j),z));
                } else if (box[i][j][z] == 0) {
                    raw++;
                }
            }

        }
    }
    if(raw==0){
        cout<<0;
    }
    else{
        cout<<bfs(n,m,h,raw,q,box);
    }
    return 0;
}