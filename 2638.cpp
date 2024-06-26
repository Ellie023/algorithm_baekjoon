#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

int N,M;
int TIME=0;

int arr[104][104];
bool visit[104][104];//외부 공기

vector<pair<pair<int,int>,bool>> liquid;//치즈가 녹았는 지
vector<pair<int,int>> cheese_next;// 녹을 치즈들
queue<pair<int,int>> bottle;//녹은 치즈 자리를 담는 큐

void air(){
    queue<pair<int,int>> q;
    q.push({0,0});
    visit[0][0]=1;
    while (!q.empty()){
        pair<int,int> cur;
        cur.first=q.front().first;
        cur.second=q.front().second;
        q.pop();
        for(int dir=0; dir<4; dir++){
            int nx=cur.first+dx[dir];
            int ny=cur.second+dy[dir];
            if(nx<0||ny<0||nx>=N||ny>=M){
                continue;
            }
            if(!visit[nx][ny]){
                visit[nx][ny]=1;
                q.push({nx,ny});
            }
        }
    }
}
void find(){
    cheese_next.clear();
    for(int i=0; i<liquid.size(); i++){
        if(liquid[i].second) continue;
        int x=liquid[i].first.first;
        int y=liquid[i].first.second;
        int cnt=0;
        for(int dir=0; dir<4; dir++){
            int nx=x+dx[dir];
            int ny=y+dy[dir];
            if(arr[nx][ny]==0&&visit[nx][ny]) cnt++;
        }
        if(cnt>=2){
            cheese_next.push_back({x,y});
            liquid[i].second=true;
        }
    }
}
void meit(){
    for(int i=0; i<cheese_next.size(); i++){
        int x=cheese_next[i].first;
        int y=cheese_next[i].second;
        arr[x][y]=0;
        bottle.push({x,y});
    }
}
bool check(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]==1){
                return false;
            }
        }
    }
    return true;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;

    for(int i=0;i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                liquid.push_back({{i,j}, false});
                visit[i][j]=1;
            }
        }
    }
    while (1){
        if(check())break;
        TIME++;
    }
    air();
    cout<<TIME;
    return 0;
}