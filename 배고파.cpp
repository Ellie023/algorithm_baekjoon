#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,m,i,j;

    cin>>n;

    while(n--){
        cin>>m;
        pair<pll,pll> ans={{2e18,2e18},{2e18,2e18}};
        for(i=0;i<60;i++) for(j=i;j<60;j++)
                ans=min(ans,pair<pll,pll>(pll(abs((1LL<<i)+(1LL<<j)-m),(1LL<+i)
                +(1LL<<j)),pll(i,j)));
        cout<<ans.second.first<<' '<<ans.second.second<<'\n';
    }



    return 0;
}