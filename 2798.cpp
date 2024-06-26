#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    int max=0;
    int total=0;
    cin>>n>>m;
    vector<int> card(n,0);

    for(int i=0; i<n; i++) {
        cin >> card[i];
    }

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                total=card[i]+card[j]+card[k];
                if(m<total){
                    continue;
                }
                if(total>max){
                    max=total;
                }
            }
        }
    }
    cout<<max;
    return 0;
}