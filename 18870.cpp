#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> v,back;

    int n,input;

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>input;
        v.push_back(input);
        back.push_back(input);

    }

    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    for(int i = 0; i < n; i++) {
        printf("%d ", lower_bound(v.begin(), v.end(), back[i]) - v.begin());
    }
    return 0;
}