#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    vector<int> a(n);

    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int L=0;
    int R=n-1;
    long long bestsum=LLONG_MAX;
    long long ansL=a[L], ansR=a[R];

    while(L<R){
        long long s=a[L]+a[R];
        if(llabs(s)<llabs(bestsum)){
            bestsum=s;
            ansL=a[L],ansR=a[R];
            if(bestsum==0) break;
        }
        if(s<0) L++;
        else R--;
    }

    cout << ansL << ' ' << ansR << '\n';
    return 0;
}
