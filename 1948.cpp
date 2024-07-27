#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    cin>>N>>M;

    vector<vector<pair<int,int>>> A;
    vector<vector<pair<int,int>>> reverseA;
    vector<int> indegree;
    A.resize(N+1);
    reverseA.resize(N+1);
    indegree.resize(N+1);

    for(int i=0; i<M; i++){
        int S,E,V;
        cin>>S>>E>>V;
        A[S].push_back(make_pair(E,V));
        reverseA[E].push_back(make_pair(S,V));
        indegree[E]++;
    }

    int startCity,endCity;
    cin>>startCity>>endCity;
    queue<int> mqueue;
    mqueue.push(startCity);
    vector<int> result;
    result.resize(N+1);

    while (!mqueue.empty ()){
        int now= mqueue.front();
        mqueue.pop();

        for(pair<int,int> next:A[now]){
            indegree[next.first]--;
            result[next.first]=max(result[next.first],result[now]+next.second);
            if(indegree[next.first]==0){
                mqueue.push(next.first);
            }
        }
    }
    int count=0;
    vector<bool> visited;
    visited.resize(N+1);
    queue<int> rqueue;
    rqueue.push(endCity);
    visited[endCity]=true;

    while (!rqueue.empty()){
        int now=rqueue.front();
        rqueue.pop();

        for(pair<int,int> next:reverseA[now]){
            if(result[next.first]+next.second==result[now]){
                count++;
                if(visited[next.first]==false){
                    visited[next.first]=true;
                    rqueue.push(next.first);
                }
            }
        }
    }
    cout<<result[endCity]<<'\n';
    cout<<count;
    return 0;
}