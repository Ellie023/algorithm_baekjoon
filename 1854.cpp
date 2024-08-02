#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int w[1001][1001];
priority_queue<int> disQ[1001];
int main() {


    typedef pair<int,int> Node;
    int n,m,k;

    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n>>m>>k;

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        w[a][b]=c;
    }


    priority_queue<Node,vector<Node>,greater<Node>> pq;
    pq.push(make_pair(0,1));
    disQ[1].push(0);

    while (!pq.empty()){
        Node u=pq.top();
        pq.pop();

        for(int adj=1; adj<=n; adj++){
            if(w[u.second][adj]!=0){
                if(disQ[adj].size()<k){
                    disQ[adj].push(u.first+w[u.second][adj]);
                    pq.push(make_pair(u.first+w[u.second][adj],adj));
                }
                else if(disQ[adj].top()>u.first+w[u.second][adj]){
                    disQ[adj].pop();
                    disQ[adj].push(u.first+w[u.second][adj]);
                    pq.push(make_pair(u.first+w[u.second][adj],adj));
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(disQ[i].size()==k){
            cout<<disQ[i].top()<<'\n';
        }
        else
            cout<<-1<<'\n';
    }
    return 0;
}