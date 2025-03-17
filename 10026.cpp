#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char map[101][101];
bool visited[101][101];

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

int ans=0;
int n;
void dfs(int a, int b){
    if(visited[a][b]) return;

    visited[a][b]=true;

    for(int i=0; i<4; i++){
        int X=dx[i]+a;
        int Y=dy[i]+b;

        if(map[X][Y]==map[a][b]&&!visited[X][Y]){
            dfs(X,Y);
        }
    }

}
void solve(){

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                dfs(i,j);
                ans++;
            }
        }
    }
}

int main() {
    string input;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>input;
        for(int j=0; j<n; j++){
            map[i][j]=input[j];
        }
    }
    solve();
    cout<<ans<<" ";
    ans=0;
    memset(visited,false,sizeof(visited));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 'G') map[i][j] = 'R';
        }

    }
        solve();

    cout<<ans;
    return 0;
}