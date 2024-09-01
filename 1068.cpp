#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> tree;
int answer=0;
int deleteNode=0;
vector<bool> visited;

void DFS(int number){
    visited[number]=true;
    int cNode=0;

    for(int i:tree[number]){
        if(visited[i]==false&&i!=deleteNode){
            cNode++;
            DFS(i);
        }
    }
    if(cNode==0){
        answer++;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    visited.resize(n);
    tree.resize(n);
    int root=0;

    for(int i=0; i<n; i++){
        int p;
        cin>>p;

        if(p!=-1){
            tree[i].push_back(p);
            tree[p].push_back(i);
        }
        else{
            root=i;
        }
    }
    cin>>deleteNode;

    if(deleteNode==root){
        cout<<0<<'\n';
    }
    else{
        DFS(root);
        cout<<answer;
    }
    return 0;
}