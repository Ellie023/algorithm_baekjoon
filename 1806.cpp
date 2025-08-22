#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {

    int N,S;
    cin>>N>>S;
    vector<int> a(N);

    for(int i=0; i<N; i++){
        cin>>a[i];
    }
    int ans=INT_MAX;
    long long sum=0;
    int left=0;

    for(int right=0; right<N; right++){
        sum+=a[right];

        while(sum>=S){
            ans=min(ans,right-left+1);
            sum-=a[left++];
        }
    }
    cout << (ans == INT_MAX ? 0 : ans) << "\n";
    return 0;
}