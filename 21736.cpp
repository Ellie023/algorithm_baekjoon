#include <iostream>
#include <queue>

using namespace std;

char map[601][601]; // map 정보
int visited[601][601]; // 방문 여부 체크
pair<int, int> I_pos; // 도연이 위치

int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};
int N,M;
int ans;
void bfs(){
    queue<pair<int,int>> q;

    q.push(I_pos);
    visited[I_pos.first][I_pos.second]=1;
    while(!q.empty()){
        pair<int,int> cur =q.front();
        q.pop();

        for(int i=0; i<4; i++){
            pair<int,int> next ={cur.first+dy[i],cur.second+dx[i]};
            if(next.first<0||next.first>=N||next.second<0||next.second>=M){continue;}
            if(map[next.first][next.second]=='X'){continue;}
            if(visited[next.first][next.second]==1){continue;}
            if(map[next.first][next.second]=='P'){ans++;}
            q.push(next);
            visited[next.first][next.second]=1;
        }
    }
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin>>N>>M;

    for(int y=0; y<N; y++){
        for(int x=0; x<M; x++){
            cin>>map[y][x];

            if(map[y][x]=='I'){
                I_pos.first=y;
                I_pos.second=x;
            }
        }
    }
    bfs();
    if(ans==0) cout<<"TT";
    else cout<<ans;
    return 0;
}