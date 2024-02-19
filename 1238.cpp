#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M,X;
const int INF=1e9+7;
vector<pair<int,int>> grape[2][1001];
vector<int> dist[2];
int resdist[1001];//X로 가는 최단거리

void dijkstra(int k){
    dist[k][X]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,X});

    while(!q.empty()){
        int min_cost=q.top().first;
        int now=q.top().second;
        q.pop();

        if(min_cost>dist[k][now]) continue;

        for(int i=0; i<grape[k][now].size(); i++){
            int next=grape[k][now][i].second;
            int next_cost=min_cost+grape[k][now][i].first;

            if(next_cost<dist[k][next]){
                dist[k][next]=next_cost;
                q.push({next_cost,next});
            }
        }

    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M>>X;
    int u,k,t;

    for(int i=0; i<M; i++){
        cin>>u>>k>>t;
        grape[0][u].push_back(make_pair(t,k));
        grape[1][k].push_back(make_pair(t,u));
    }
    dist[0].resize(N+1,INF);
    dist[1].resize(N+1,INF);

    dijkstra(1);
    dijkstra(0);

    int result=0;
    for(int i=1; i<=N; i++){
        result=max(result,dist[0][i]+dist[1][i]);
    }
    cout<<result;

    return 0;
}