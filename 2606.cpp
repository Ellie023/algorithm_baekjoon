#include <iostream>
#include "queue"

using namespace std;

typedef vector<vector<int>> vec_vec;

vector<bool> visited_dfs;

void dfs(int node, vec_vec &graph){
    visited_dfs[node]= true;

    for(int i=0; i<graph[node].size(); i++){
        int next_node=graph[node][i];
        if(!visited_dfs[next_node]){
            dfs(next_node,graph);
        }
    }
}
int bfs(int n,int v, vec_vec &graph){
    int cnt=0;
    vector<bool> visited (n+1,false);
    queue<int> q;

    q.push(v);
    visited[v]= true;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(const auto& next_node:graph[node]){
            if(!visited[next_node]){
                q.push(next_node);
                visited[next_node]= true;
                cnt++;
            }
        }
    }
    return cnt;
}
int main() {

    int n,m,n1,n2;
    vec_vec graph;

    cin>>n>>m;
    graph.assign(n+1,vector<int> (0));
    while(m--){
        cin>>n1>>n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    cout<<bfs(n,1,graph);
    return 0;
}