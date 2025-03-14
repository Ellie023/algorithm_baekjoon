#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int cnt[10]={0};
    int type=0;
    int ans=0;
    cin>>n;
    vector<int> fruit(n);

    for(int i=0; i<n; i++){
        cin>>fruit[i];
    }
    if(n<=2) {
        cout << n;
        return 0;
    }
    int left=0, right=0;

    while(right < n) {
        if(cnt[fruit[right]] == 0) {
            type++;
        }
        cnt[fruit[right]]++;

        while(type > 2) {
            cnt[fruit[left]]--;
            if(cnt[fruit[left]] == 0) {
                type--;
            }
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    cout<<ans;

    return 0;
}