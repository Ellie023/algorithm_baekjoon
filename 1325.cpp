#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//dfs로 해킹 가능한 컴퓨터 세기

vector<bool> visited; //컴퓨터 해킹 했나? == 방문 여부
int dfs(int node, vector<vector<int>> &grape){
    int cnt=1;
    visited[node]=true;
    for(int i=0; i<grape[node].size(); i++){
        int next_node=grape[node][i];
        if(!visited[next_node]){//해킹 안 함
            cnt+=dfs(next_node,grape);
        }
    }
    return cnt;
}

vector<int> hacking(int n, vector<vector<int>> &grape){
    int max =0;
    vector<int> result;

    for(int i=1; i<=n; i++){
        visited.assign(n+1,false);
        int cnt=dfs(i,grape);

        if(cnt>max){//해킹 가능한 최댓값이 바뀜
            max=cnt;
            result = {i};
        }
        else if(cnt == max) {
            result.push_back(i);
        }
    }
    return result;

}
int main() {

    int n,m,a,b;
    vector<vector<int>> graph;
    //입력
    cin>>n>>m;
    graph.assign(n+1,vector<int>(0));
    while(m--){
       cin>>a>>b;
       graph[b].push_back(a);//b가 a를 해킹 할 수 있다.(단방향)
    }
    vector<int> result =hacking(n,graph);
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    return 0;
}