#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long mdistance[101][101];

    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>mdistance[i][j];
        }
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mdistance[i][k]==1&&mdistance[k][j]==1){
                    mdistance[i][j]=1;
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<mdistance[i][j]<<' ';
        }
        cout<<"\n";
    }
    return 0;
}