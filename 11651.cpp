#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<pair<int,int>> a(n,pair<int,int>(0,0));

    for(int i=0; i<n; i++){
        cin>>a[i].second>>a[i].first;
    }
    sort(a.begin(),a.end());

    for (int i = 0; i < n; i++) {
        cout<<a[i].second<<" "<<a[i].first<<"\n";
    }
    return 0;
}