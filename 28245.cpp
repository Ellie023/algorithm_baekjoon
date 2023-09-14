#include <iostream>
using namespace std;
typedef long long ll;
const int MAX = 60;
pair<int, int> getPair(ll m) {
    if(m==1) return {0,0};
    int x, y;

    ll n=m-1;
    ll k=m+1;
    int a=0;

    for (ll i = 1; i < MAX; i++) {
        if (m == ((ll)1 << i)||n == ((ll)1 << i)) {
            return {i - 1, i - 1};
        }
        if(k==(ll)1<<i)
            a=i;
    }
    int b=0,c=0;
        for (x = MAX; x >=0 ; x--) {
            if (m & ((ll) 1 << x)) {
                break;
            }
        }
        for (y = x - 1; y >=0; y--) {
            if(k & ((ll) 1 << y)){
                c=y;
            }
            if (m &((ll) 1 << y)) {
                return {y, x};
            }
        }

        b=x;
        c=y+1;
    if ((2^y+1+2^x)<a) {

        return {a-1,a-1};
    }
    return {c,b};



}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    ll m;

    cin >> n;
    while (n--) {
        cin >> m;
        pair<int, int> ans = getPair(m);
        cout << ans.first << " " << ans.second << "\n";
    }

    return 0;
}