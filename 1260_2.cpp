#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(int cur, const auto& adj, auto& visited, auto& res){
    visited[cur]=true;
    res.push_back(cur);
    for(int nxt:adj[cur]){
        if(visited[nxt]) continue;
            dfs(nxt,adj,visited, res);
    }
}
void bfs(int s, const auto& adj, auto& visited, auto& res){
    vector<int> q(1,s);
    visited[s]=true;
    while(!q.empty()){
        vector<int> nq;
        for(int cur:q){
            res.push_back(cur);
            for(int nxt:adj[cur]){
                if(visited[nxt]) continue;
                visited[nxt]=true;
                nq.push_back(nxt);
            }
        }
        q=nq;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0); // Optimize I/O
    int n, m, s;                    // n: 노드 수, m: 간선 수, s: 시작 노드
    cin >> n >> m >> s;             // 그래프 정보 입력

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;              // 간선 정보 입력
        adj[a].push_back(b);        // 무방향 그래프이므로 양쪽 모두 추가
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end()); // 작은 숫자부터 방문하도록 정렬
    }

    vector<bool> visited(n + 1, false); // 노드 방문 여부를 저장하는 배열
    vector<int> r1;                     // DFS 결과 리스트
    dfs(s, adj, visited, r1);           // DFS 호출

    fill(visited.begin(), visited.end(), false); // 방문 배열 초기화
    vector<int> r2;                              // BFS 결과 리스트
    bfs(s, adj, visited, r2);                    // BFS 호출

    for (int x : r1) cout << x << ' '; cout << '\n'; // DFS 결과 출력
    for (int x : r2) cout << x << ' '; cout << '\n'; // BFS 결과 출력
    return 0;
}