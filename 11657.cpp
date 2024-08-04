#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>
using namespace std;

typedef tuple<int,int,int> edge;
int n,m;
vector<long> mdistance;
vector<edge> edges;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    mdistance.resize(n+1);
    std::fill(mdistance.begin(),mdistance.end(),LONG_MAX);

    for(int i=0; i<m; i++){
        int start,end,time;
        cin>>start>>end>>time;
        edges.push_back(make_tuple(start,end,time));
    }
    mdistance[1]=0;
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            edge m=edges[j];
            int start=get<0>(m);
            int end =get<1>(m);
            int time=get<2>(m);
            if(mdistance[start]!=LONG_MAX&&mdistance[end]>mdistance[start]+time){
                mdistance[end]=mdistance[start]+time;
            }
        }
    }
    bool mCycle= false;

    for(int i=0; i<m; i++){
        edge m =edges[i];
        int start =get<0>(m);
        int end =get<1>(m);
        int time=get<2>(m);
        if(mdistance[start]!=LONG_MAX&&mdistance[end]>mdistance[start]+time){
            mCycle= true;
        }
    }
    if(!mCycle){
        for(int i=2; i<=n; i++){
            if(mdistance[i]==LONG_MAX){
                cout<<-1<<'\n';
            }
            else{
                cout<<mdistance[i]<<'\n';
            }
        }
    } else{
        cout<<-1<<'\n';
    }
    return 0;
}