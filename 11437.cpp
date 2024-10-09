#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int n,m;
vector<vector<int>> tree;
vector<int> depth;
vector<int> parent;
vector<bool> visited;

void BFS(int node){
    queue<int> myqueue;
    myqueue.push(node);
    visited[node]=true;

    int level=1;
    int now_size=1;
    int count=0;

    while(!myqueue.empty()){
        int now_node = myqueue.front();
        myqueue.pop();
        for(int next:tree[now_node]){
            if(!visited[next]){
                visited[next]=true;
                myqueue.push(next);
                parent[next]=now_node;
                depth[next]=level;
            }
        }
        count++;
        if(count==now_size){
            count=0;
            now_size=myqueue.size();
            level++;
        }
    }
}
int executeLCA(int a, int b){
    if(depth[a]<depth[b]){
        int temp=a;
        a=b;
        b=temp;
    }
    while(depth[a]!=depth[b]){
        a=parent[a];
    }
    while(a!=b){
        a=parent[a];
        b=parent[b];
    }
    return a;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    tree.resize(n+1);
    depth.resize(n+1);
    parent.resize(n+1);
    visited.resize(n+1);

    for(int i=0; i<n-1; i++){
        int s,e;
        cin>>s>>e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }

    BFS(1);
    cin>>m;
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        cout<<executeLCA(a,b)<<'\n';

    }
    return 0;
}