#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int parent[100001];
int result;

int getParent(int num){
    if(num==parent[num]) return num;
    return parent[num]= getParent(parent[num]);
}
void unionParent(int a,int b){
    a= getParent(a);
    b= getParent(b);

    if(a!=b){
        parent[a]=b;
    }
}
bool findParent(int a,int b){
    a= getParent(a);
    b= getParent(b);
    if(a==b){
        return true;
    }
    else{
        return false;
    }
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<pair<int,pair<int,int>>> edge(M);
    //vector<int> grape[2];
    for(int i=0; i<M; i++){
        int cost,a,b;
        cin>>a>>b>>cost;
        edge[i]={cost,{a,b}};
    }
    for(int i=1; i<=N;i++){
        parent[i]=i;
    }
    sort(edge.begin(),edge.end());
    int maxCost=0;
    for(int i=0; i<M; i++){
        int cost=edge[i].first;
        int a=edge[i].second.first;
        int b=edge[i].second.second;
        if(!findParent(a,b)){
            maxCost= max(maxCost,cost);
            result+=cost;
            unionParent(a,b);
        }
    }
    cout<<result-maxCost;
    return 0;
}