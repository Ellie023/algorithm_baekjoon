#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int n;
vector<pair<int,int>> M;
long D[502][502];

int execute(int s,int e){
    int result=INT_MAX;

    if(D[s][e]!=-1){
        return D[s][e];
    }
    if(s==e){
        return 0;
    }
    if(s+1==e){
        return M[s].first*M[s].second*M[e].second;
    }
    for(int i=s;i<e; i++){
        result=min(result,M[s].first*M[i].second*M[e].second+execute(s,i)+execute(i+1,e));
    }
    return D[s][e]=result;
}

int main() {
    cin>>n;
    M.resize(n+1);

    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            D[i][j]=-1;
        }
    }
    for(int i=1; i<=n; i++){
        int y,x;
        cin>>y>>x;
        M[i]=make_pair(y,x);
    }
    cout<<execute(1,n);
    return 0;
}