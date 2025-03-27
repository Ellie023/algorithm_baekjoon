#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 9

int N,M;
int ans[MAX];
int arr[MAX];
bool visited[MAX];
set<vector<int>> s;

void dfs(int k){
    if(k==M){
        vector<int> v;
        for(auto i=0; i<M; i++){
            v.push_back(ans[i]);
        }
        s.insert(v);
        v.clear();
    }
    else{
        for(auto i=0; i<N; i++){
            if(!visited[i]){
                visited[i]=true;
                ans[k]=arr[i];
                dfs(k+1);
                visited[i]=false;
            }
        }
    }
}

int main() {

    cin>>N>>M;

    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    sort(arr,arr+N);
    dfs(0);
    for(auto vector:s){
        for(auto temp:vector){
            cout<<temp<<" ";
        }
        cout<<'\n';
    }
    return 0;


}