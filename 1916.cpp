#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INT=INT_MAX;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n+1);

    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }
    int start,end;
    cin>>start>>end;

    vector<int> dist(n+1,INT);

    dist[start]=0;

    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<>> pq;
    pq.push({0,start});

    while(!pq.empty()){
        auto [cost,now]=pq.top();
        pq.pop();

        if(cost>dist[now]) continue;

        for(auto& [next,weight]:graph[now]){
            int nextCost=cost+weight;
            if(nextCost<dist[next]){
                dist[next]=nextCost;
                pq.push({nextCost,next});
            }
        }
    }

    cout<<dist[end]<<'\n';
    return 0;
}