#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

const int MAX =10001;

vector<pair<int,int>> adj[MAX];
bool visited[MAX];
int maxDist=0;
int farthestNode=0;

void dfs(int node, int dist){
    visited[node]=true;

    if(dist>maxDist){
        maxDist=dist;
        farthestNode=node;
    }
    for(auto& next:adj[node]){
        int nextnode=next.first;
        int cost=next.second;
        if(!visited[nextnode]){
            dfs(nextnode,dist+cost);
        }
    }




}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    for(int i=0; i<n-1; i++){
        int parent,child,weight;
        cin>>parent>>child>>weight;

        adj[parent].push_back({child,weight});
        adj[child].push_back({parent,weight});
    }
    memset(visited,false,sizeof(visited));
    dfs(1,0);

    memset(visited,false,sizeof(visited));
    maxDist=0;
    dfs(farthestNode,0);
    cout<<maxDist<<endl;
    return 0;
}