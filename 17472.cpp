#include <iostream>
#include <queue>
using namespace std;

static int dr[]={-1,0,1,0};
static int dc[]={0,1,0,-1};
static int map[101][101];
static bool visited[101][101]={false};
static vector<int> parent;
static int N,M,sNum;
static vector<vector<pair<int,int>>>  sumlist;
static vector<pair<int,int>> mlist;

typedef struct Edge{
    int s,e,v;
    bool operator>(const Edge& temp) const{//연산자 오버로딩
        return v>temp.v; //temp.v를 어디에 둘 지 결정한다.
    }
}Edge;
static priority_queue<Edge,vector<Edge>,greater<Edge>> pq;
void BFS(int i, int j){
    queue<pair<int,int>> myqueue;
    mlist.clear();
    myqueue.push(make_pair(i,j));
    mlist.push_back(make_pair(i,j));
    visited[i][j]=true;
    map[i][j]=sNum;

    while(!myqueue.empty()){
        int r=myqueue.front().first;
        int c=myqueue.front().second;
        myqueue.pop();

        for(int d=0; d<4; d++){
            int tempR=dr[d];
            int tempC=dc[d];
            while(r+tempR>=0&& r+tempR<N&&c+tempC>=0&&c+tempC<M){
                if(visited[r+tempR][c+tempC]==false&&map[r+tempR][c+tempC]!=0){
                    int now_i =r+tempR;
                    int now_j=c+tempC;
                    map[now_i][now_j]=sNum;
                    visited[now_i][now_j]=true;
                    mlist.push_back(make_pair(now_i,now_j));
                    myqueue.push(make_pair(now_i,now_j));
                }
                else{
                    break;
                }
                if(tempR<0){
                    tempR--;
                }
                else if(tempR>0){
                    tempR++;
                }
                else if(tempC<0){
                    tempC--;
                }
                else if(tempC>0){
                    tempC++;
                }
            }
        }
    }
}
int find(int a)
{
    if(a==parent[a]){
        return a;
    }
    else{
       return parent[a]=find(parent[a]);
    }
}
void munion (int a, int  b){
    a=find(a);
    b=find(b);

    if(a!=b){
        parent[b]=a;
    }
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
        }
    }
    sNum=1;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j]!=0&&visited[i][j]!=true){
                BFS(i,j);
                sNum++;
                sumlist.push_back(mlist);
            }
        }
    }
    for(int i=0; i<sumlist.size(); i++){
        vector<pair<int,int>> now=sumlist[i];

        for(int j=0; j<now.size(); j++){
            int r = now[j].first;
            int c= now[j].second;
            int now_S =map[r][c];

            for(int d=0; d<4; d++){
                int tempR =dr[d];
                int tempC = dc[d];
                int blenght=0;
                while(r+tempR>=0&& r+tempR<N&&c+tempC>=0&&c+tempC<M){
                    if(map[r+tempR][c+tempC]==now_S){
                        break;
                    }
                    else if(map[r+tempR][c+tempC]!=0){
                        if(blenght>1){
                            pq.push(Edge{now_S,map[r+tempR][c+tempC],blenght});
                        }
                        break;
                    }
                    else{
                        blenght++;
                    }
                    if(tempR<0){
                        tempR--;
                    }
                    else if(tempR>0){
                        tempR++;
                    }
                    else if(tempC<0){
                        tempC--;
                    }
                    else if(tempC>0){
                        tempC++;
                    }
                }
            }
        }
    }

    parent.resize(sNum+1);
    for(int i=1; i<parent.size(); i++){
        parent[i]=i;
    }
    int useEdge=0;
    int result=0;
    while(!pq.empty()){
        Edge now =pq.top();
        pq.pop();
        if(find(now.s)!=find(now.e)){
            munion(now.s,now.e);
            result+=now.v;
            useEdge++;
        }
    }
    if(useEdge==sNum-2){
        cout<<result<<'\n';
    }
    else{
        cout<<-1<<'\n';
    }

    return 0;
}