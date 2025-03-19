#include <iostream>
#include <queue>

using namespace std;

int map[102]={0};
bool visited[102];

void bfs(int x, int c){

    queue<pair<int,int>> q;
    q.push(make_pair(x,c));
    while(!q.empty()){
        int loc =q.front().first;
        int cnt=q.front().second;
        q.pop();

        for(int i=1; i<=6; i++){
            int nx=loc+i;
            if(nx==100){
                cout<<cnt+1;
                return;
            }
            else{
                while(map[nx]!=0){
                    nx=map[nx];
                }
                if(!visited[nx]){
                    q.push(make_pair(nx,cnt+1));
                    visited[nx]=true;
                }
            }
        }
    }
}

int main() {

    int n,m,a,b;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>a>>b;
        map[a]=b;
    }
    for(int i=0; i<m; i++){
        cin>>a>>b;
        map[a]=b;
    }
    bfs(1,0);
    return 0;
}