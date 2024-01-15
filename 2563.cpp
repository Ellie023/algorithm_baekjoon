#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;
    cin>>n;
    vector<vector<int>> v(100,vector<int>(100));
    int x,y,cnt=0;
    while (n--){
        cin>>x>>y;
        for(int i=y;i<y+10;i++){
            for(int j=x;j<x+10;j++){
                if(!v[i][j]){
                    cnt++;
                    v[i][j]=1;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}