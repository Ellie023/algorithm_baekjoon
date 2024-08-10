#include <iostream>
#include <limits.h>

int n,m;
long mdistance[101][101];


using namespace std;

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
                mdistance[i][j]=1000001;
            }
        }
    }
    for(int i=0; i<m; i++){
        int s,e;
        cin>>s>>e;
        mdistance[s][e]=1;
        mdistance[e][s]=1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(mdistance[j][k]>mdistance[j][i]+mdistance[i][k]){
                    mdistance[j][k]=mdistance[j][i]+mdistance[i][k];
                }
            }
        }
    }
    int Min=INT_MAX;
    int Answer=-1;

    for(int i=1; i<=n; i++){
        int temp=0;
        for(int j=1; j<=n; j++){
            temp=temp+mdistance[i][j];
        }
        if(Min>temp){
            Min=temp;
            Answer=i;
        }
    }
    cout<<Answer;
    return 0;
}