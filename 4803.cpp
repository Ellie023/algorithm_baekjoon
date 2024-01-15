#include <iostream>
#include <vector>

using namespace std;
void printResult(int tc, int cnt) {
    cout << "Case " << tc << ": ";

    switch (cnt) {
        case 0:
            cout << "No trees.\n";
            break;
        case 1:
            cout << "There is one tree.\n";
            break;
        default:
            cout << "A forest of " << cnt << " trees.\n";
    }
}

    void dfs(bool &flag,int cur, int prev, vector<vector<int>>& graph, vector<bool>& visited){
    if(visited[cur]){
        flag= false;
        return;
    }
    visited[cur]=true;
    for (int next : graph[cur]) {
        if (next == prev) {
            continue;
        }
        dfs(flag, next, cur, graph, visited);
    }
    return ;

}
int main() {

    int n,m,t,v1,v2;
    for(t=1;; t++){
        cin>>n>>m;

        if(!n&&!m){
            break;
        }
        vector<vector<int>> grape(n+1, vector<int>(0));
        for(int i=0; i<m; i++){
            cin>>v1>>v2;
            grape[v1].push_back(v2);
            grape[v2].push_back(v1);
        }
        int cnt=0;
        vector<bool> visited(n+1, false);
        for(int i=1; i<=n; i++){
            if(visited[i]){
                continue;
            }
            bool flag=true;
            dfs(flag,i,0,grape,visited);
            if(flag){
                cnt++;
            }

        }
        printResult(t,cnt);
    }

    return 0;
}