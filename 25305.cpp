#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N,k;
    cin>>N>>k;
    vector<int> v(N,0);

    for(int u=0; u<N; u++){
        cin>>v[u];
    }
    sort(v.begin(),v.end(),greater<>());

    cout<<v[k-1];
    return 0;
}