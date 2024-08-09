#include <iostream>

using namespace std;

static int n,m;
static long mdistance[101][101];
const int Max =10000001;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j){
                mdistance[i][j]=0;
            }
            else{
                mdistance[i][j]=Max;
            }
        }
    }
    for(int i=0; i<m; i++){
        int s,e,v;
        cin>>s>>e>>v;
        if(mdistance[s][e]>v){
            mdistance[s][e]=v;
        }
    }
    for(int k=1; k<=n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (mdistance[i][j]>mdistance[i][k]+mdistance[k][j]){
                    mdistance[i][j]=mdistance[i][k]+mdistance[k][j];
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(mdistance[i][j]==Max){
                cout<<"0"<<" ";
            }
            else{
                cout<<mdistance[i][j]<<" ";
            }
        }
        cout<<'\n';
    }
    return 0;
}