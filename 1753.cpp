#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;



int main() {

    typedef pair<int,int> edge;
    int V,E,K;
    vector<int> distancem;
    vector<bool> visited;
    vector<vector<edge>> listm;
    priority_queue<edge,vector<edge>,greater<edge>> q;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>V>>E>>K;
    distancem.resize(V+1);
    std::fill(distancem.begin(),distancem.end(),INT_MAX);
    visited.resize(V+1);
    std::fill(visited.begin(),visited.end(), false);
    listm.resize(V+1);

    for(int i=0; i<E; i++){
        int u,v,w;
        cin>>u>>v>>w;
        listm[u].push_back(make_pair(v,w));
    }
    q.push(make_pair(0,K));
    distancem[K]=0;
    while (!q.empty()){
        edge current = q.top();
        q.pop();
        int c_v=current.second;
        if(visited[c_v]){
            continue;
        }
        visited[c_v]=true;

        for(int t=0; t<listm[c_v].size(); t++){
            edge tmp=listm[c_v][t];
            int next=tmp.first;
            int value=tmp.second;

            if(distancem[next]>distancem[c_v]+value){
                distancem[next]=value+distancem[c_v];
                q.push(make_pair(distancem[next],next));
            }
        }
    }
    for(int i=1; i<=V; i++){
        if(visited[i]){
        cout<<distancem[i]<<'\n';}
        else { cout << "INF" << '\n'; }
    }
    return 0;
}