#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>
using namespace std;

typedef tuple<int,int,int> edge;
int n,m,citys,citye;
vector<long> mdistance, citymoney;
vector<edge> edges;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>citys>>citye>>m;
    mdistance.resize(n);
    citymoney.resize(n);
    fill(mdistance.begin(),mdistance.end(),LONG_MIN);

    for(int i=0; i<m; i++) {
        int start, end, price;
        cin >> start >> end >> price;
        edges.push_back(make_tuple(start, end, price));
    }
    for(int i=0; i<n; i++){
        cin>>citymoney[i];
    }
    mdistance[citys]=citymoney[citys];
    for(int i=0; i<=n+50; i++){
        for(int j=0; j<m; j++){
            int start=get<0>(edges[j]);
            int end=get<1>(edges[j]);
            int price = get<2>(edges[j]);
            if(mdistance[start]==LONG_MIN){
                continue;
            }
            else if(mdistance[start]==LONG_MAX){
                mdistance[end]=LONG_MAX;
            }
            else if(mdistance[end]<mdistance[start]+citymoney[end]-price){
                mdistance[end]=mdistance[start]+citymoney[end]-price;
                if(i>=n-1){
                    mdistance[end]=LONG_MAX;
                }
            }
        }
    }
    if(mdistance[citye]==LONG_MIN){
        cout<<"gg"<<'\n';
    }
    else if(mdistance[citye]==LONG_MAX){
        cout<<"Gee"<<'\n';
    }
    else{
        cout<<mdistance[citye]<<'\n';
    }

    return 0;
}