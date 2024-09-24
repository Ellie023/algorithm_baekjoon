#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> wait(n,0);

    for(int i=0; i<n; i++) {
        cin >> wait[i];
    }
    sort(wait.begin(),wait.end());
    int result=0;

    for(int i=0; i<n; i++){
        result+=wait[i]*(n-i);
    }
    cout<<result;
    return 0;
}