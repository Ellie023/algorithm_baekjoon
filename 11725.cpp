#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> answer;
vector<bool> visited;
vector<vector<int>> tree;

void DFS(int number){
    visited[number] = true;
    for(int i: tree[number]){
        if(!visited[i]){
            answer[i]=number;
            DFS(i);
        }
    }
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    visited.resize(n+1);
    tree.resize(n+1);
    answer.resize(n+1);

    for(int i=1; i<n; i++){
        int n1,n2;
        cin>>n1>>n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }
    DFS(1);
    for(int i=2; i<=n; i++){
        cout<<answer[i]<<"\n";
    }
    return 0;
}