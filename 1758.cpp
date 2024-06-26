#include <iostream>
#include "vector"
#include "algorithm"
using namespace std;

long long cal(int n, vector<int>& tips){
    long long ans=0;
    int m=1;
    for(int i=0; i<n; i++){
        int cur=tips[i]-i;

            if (cur < 0) //음수면 팁에 더하지 않는데 처음에 내림차순 정렬했으므로 아예 break
                break;
            ans+=cur;

    }
    return ans;
}

int main() {
    int n;
    cin>>n;

    vector<int> tips(n,0);

    for(int i=0; i<n; i++){
        cin>>tips[i];
    }
    sort(tips.begin(),tips.end(),greater<>());
    cout<<cal(n,tips);
    return 0;
}