#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> A;
vector<int> ans;
vector<int> visited;

void BFS(int node){
    queue<int> queue;
    queue.push(node);
    visited[node]++;

    while (!queue.empty()){
        int now_node=queue.front();
        queue.pop();
        for(int i: A[now_node])
        {
            if(visited[i]==-1){
                visited[i]=visited[now_node]+1;
                queue.push(i);
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long n,m,k,x;

    cin>>n>>m>>k>>x;
    A.resize(n+1);
    visited.resize(n+1);
    for(int i=0; i<m; i++){
        int start,end;
        cin>>start>>end;
        A[start].push_back(end);
    }
    for(int i=0; i<=n; i++){
        visited[i]=-1;
    }
    BFS(x);

    for(int i=0; i<=n; i++){
        if(visited[i]==k){
            ans.push_back(i);
        }
    }
    if(ans.empty()){
        cout<<-1<<"\n";
    }
    else{
        sort(ans.begin(),ans.end());
        for(int tmp:ans){
            cout<<tmp<<"\n";
        }
    }
    return 0;

}