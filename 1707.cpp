#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> A;

static vector<int> check;

static vector<bool> visited;

static bool IsEven;

void DFS(int node){

    visited[node]=true;

    for(int i:A[node]){
        if(!visited[i]){

            check[i]=(check[node]+1)%2;
            DFS(i);
        }
        else if(check[node]==check[i]){
            IsEven= false;
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin>>K;
    for(int t=0; t<K; t++){
        int V,E;
        cin>>V>>E;
        A.resize(V+1);
        visited.resize(V+1);
        check.resize(V+1);
        IsEven= true;
        for(int i=0; i<E; i++) {
            int S,E;
            cin>>S>>E;
            A[S].push_back(E);
            A[E].push_back(S);
        }
        for(int i=1; i<=V; i++) {
            if (IsEven) {
                DFS(i);
            } else {
                break;
            }
        }
            if(IsEven){
                cout<<"YES"<<"\n";
            }
            else{
                cout<<"NO"<<"\n";
            }
            for(int i=0; i<=V; i++){
                A[i].clear();
                visited[i]= false;
                check[i]=0;
            }
        }

    return 0;
}